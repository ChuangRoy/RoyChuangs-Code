from vpython import *
g = 9.8
size = 0.05
L = 0.5
k = 100000
damp = -1
m = 0.1
theta = 30 * pi/180
Fg = m*vector(0,-g,0)
scale = 0.3

v0 = L * sin(theta) / sqrt(L*cos(theta)/g)

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
ball = sphere(radius = size,  color=color.yellow, make_trail = True, retain = 1000, interval=1)
rod = cylinder(radius=size/10)

ball.pos = vector(L*sin(theta), -L*cos(theta), 0)
ball.v = vector(0, 0, v0)
rod.pos = vector(0, 0, 0)

dt = 0.001
t = 0.0

v_text = label(box = False, opacity = 0, height = 25, color=color.green, text = 'v')
Fs_text = label(box = False, opacity = 0, height = 25, color=color.white, text = 'Fs')
mg_text = label(box = False, opacity = 0, height = 25, color=color.yellow, text = 'Fg')
Ftot_text = label(box = False, opacity = 0, height = 25, color=color.red, text = 'F_tot')
v_vector = arrow(shaftwidth = 0.02, color=color.green)
Ftot_vector = arrow(shaftwidth = 0.02, color=color.red)
mg_vector = arrow(shaftwidth = 0.02, color=color.yellow)
Fs_vector = arrow(shaftwidth = 0.02, color=color.white)

while True:
    rate(1/dt)
    rod.axis = ball.pos - rod.pos
    ball.a = (Fg + SpringForce(rod.axis,L) - SpringDamp(ball.v, rod.axis))/m

    ball.v += ball.a*dt
    ball.pos += ball.v*dt
    t += dt

    v_vector.pos = ball.pos
    Ftot_vector.pos = ball.pos
    mg_vector.pos = ball.pos
    Fs_vector.pos = ball.pos

    v_vector.axis = ball.v*scale
    Ftot_vector.axis = (Fg + SpringForce(rod.axis,L))*scale
    mg_vector.axis = Fg*scale
    Fs_vector.axis = SpringForce(rod.axis,L)*scale
    v_text.pos = v_vector.pos + v_vector.axis*1.2
    Ftot_text.pos = Ftot_vector.pos + Ftot_vector.axis*1.2
    mg_text.pos = mg_vector.pos + mg_vector.axis*1.2
    Fs_text.pos = Fs_vector.pos + Fs_vector.axis*1.2

    if ball.v.x > 0 and ball.v.x + ball.a.x*dt < 0 :
        print ('simulated period =', t, ',\ntheoretical period = ', 2*pi*(L*cos(theta)/g)**0.5 )
        t = 0