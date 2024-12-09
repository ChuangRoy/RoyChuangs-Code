from vpython import *
g = 9.8
size = 0.05
L = 0.5
k = 100000
damp = -1
m = 0.1
theta = 60 * pi/180
Fg = m*vector(0,-g,0)
scale = 0.3

def SpringForce(r,L):
    return -k*(mag(r)-L)*r/mag(r)

def SpringDamp(v, r):
    cos_theta = dot(v,r)/((mag(v)*mag(r)) + 0.0000000001)
    r_unit_vector = norm(r)
    projection_vector = mag(v) * cos_theta * r_unit_vector
    spring_damp = - damp * projection_vector
    return spring_damp

scene = canvas(width=600, height=600, center=vector(0, -L*0.8, 0), range=1.2*L)
ceiling = box(length=0.4, height=0.005, width=0.4, opacity = 0.2)
ball_1 = sphere(radius = size,  color=color.red, make_trail = True, retain = 1000, interval=1)
ball_2 = sphere(radius = size,  color=color.green, make_trail = True, retain = 1000, interval=1)
rod_1 = cylinder(radius=size/10)
rod_2 = cylinder(radius=size/10)

ball_1.pos = vector(L*sin(theta), -L*cos(theta), 0)
ball_1.v = vector(0, 0, 0)
ball_2.pos = vector(2*L*sin(theta), -2*L*cos(theta), 0)
ball_2.v = vector(0, 0, 0)
rod_1.pos = vector(0, 0, 0)
rod_2.pos = ball_1.pos
rod_2.axis = ball_2.pos - rod_2.pos

energy_graph = graph(title="Energy vs Time", xtitle="Time (s)", ytitle="Energy (J)", width=800, height=250)
E_curve = gcurve(color=color.black, label="Mechanical Energy")
K_curve = gcurve(color=color.orange, label="Kinetic Energy")
Ug_curve = gcurve(color=color.red, label="Potential Energy")

dt = 0.001
t = 0.0

while True:
    rate(1/dt)
    rod_1.axis = ball_1.pos - rod_1.pos
    F1 = vector(0, -m*g, 0) + SpringForce(rod_1.axis, L) - SpringForce(rod_2.axis, L) - SpringDamp(ball_1.v, rod_1.axis) + SpringDamp(ball_1.v, rod_2.axis)
    ball_1.a = F1 / m
    ball_1.v += ball_1.a*dt
    ball_1.pos += ball_1.v*dt

    rod_2.pos = ball_1.pos
    rod_2.axis = ball_2.pos - rod_2.pos
    F2 = vector(0, -m*g, 0) + SpringForce(rod_2.axis, L) - SpringDamp(ball_2.v, rod_2.axis)
    ball_2.a = F2 / m
    ball_2.v += ball_2.a*dt
    ball_2.pos += ball_2.v*dt

    Ug = m * g * ball_1.pos.y + m * g * ball_2.pos.y
    K = 0.5 * m * mag(ball_1.v)**2 + 0.5 * m * mag(ball_2.v)**2
    E = Ug + K
    E_curve.plot(t, E)
    K_curve.plot(t, K)
    Ug_curve.plot(t, Ug)


    t += dt
