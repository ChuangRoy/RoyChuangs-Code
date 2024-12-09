from vpython import *

g = 10
size = 0.05
L = 0.5
k = 10
damp = 0.1
# damp = 0
m = 0.1
Fg = m*vector(0,-g,0)

def SpringForce(r,L):
    return -k*(mag(r)-L)*r/mag(r)

def AirResistance (ball):
    return -damp * ball.v

gd = graph(title = "K:green Us:red Ug:blue Total:black", width=600, height=400, xtitle="t", ytitle="energy")
fk = gcurve(color=color.green)
fus = gcurve(color=color.red)
fug = gcurve(color=color.blue)
ftotal = gcurve(color=color.black)

scene = canvas(width=600, height=600, center=vector(0, -L*0.8, 0), range=1.2*L)
ceiling = box(length=0.4, height=0.005, width=0.4, opacity = 0.2)
ball_1 = sphere(radius = size,  color=color.red, make_trail = True, retain = 1000, interval=1)
ball_2 = sphere(radius = size,  color=color.red, make_trail = True, retain = 1000, interval=1)
spring_1 = helix(radius=0.02, thickness =0.01)
spring_2 = helix(radius=0.02, thickness =0.01)

ball_1.pos = vector(0, -L, 0)
ball_1.v = vector(0, 0, 0)
ball_2.pos = vector(0, -2*L, 0)
ball_2.v = vector(0, 0, 0)
spring_1.pos = vector(0, 0, 0)
spring_2.pos = vector(0, -L, 0)

t = 0
dt = 0.001
rest_a = 0
while t < 10:
    rate(2/dt)
    spring_1.axis = ball_1.pos - spring_1.pos

    spring_2.pos = ball_1.pos
    spring_2.axis = ball_2.pos - spring_2.pos

    ball_2.a = (Fg + SpringForce(spring_2.axis,L) + AirResistance(ball_2))/m
    ball_1.a = (Fg + SpringForce(spring_1.axis,L) + AirResistance(ball_1) - SpringForce(spring_2.axis,L))/m
    ball_1.v += ball_1.a*dt
    ball_1.pos += ball_1.v*dt

    ball_2.v += ball_2.a*dt
    ball_2.pos += ball_2.v*dt
    if ball_2.pos.y + size >= ball_1.pos.y:
        ball_2.pos.y = ball_1.pos.y - size - 1e-100
    t += dt

ball_1.make_trail = 0
ball_1.clear_trail()
ball_2.make_trail = 0
ball_2.clear_trail()
t = 0

while 1:
    rate(1/dt)
    spring_2.pos = ball_1.pos
    spring_2.axis = ball_2.pos - spring_2.pos

    ball_2.a = (Fg + SpringForce(spring_2.axis,L))/m
    ball_1.a = (Fg - SpringForce(spring_2.axis,L))/m
    ball_1.v += ball_1.a*dt
    ball_1.pos += ball_1.v*dt

    ball_2.v += ball_2.a*dt
    ball_2.pos += ball_2.v*dt
    if ball_2.pos.y + size >= ball_1.pos.y:
        ball_2.pos.y = ball_1.pos.y - size - 1e-100

    Ug = m * g * (ball_1.pos.y + L) + m * g * (ball_2.pos.y + L)
    Us =  0.5 * k * (mag(spring_2.axis) - L)**2
    EK = 0.5 * m * mag(ball_1.v)**2 + 0.5 * m * mag(ball_2.v)**2

    E = Ug + Us + EK

    fk.plot(pos=(t, EK))
    fus.plot(pos=(t, Us))
    fug.plot(pos=(t, Ug))
    ftotal.plot(pos=(t, EK + Us + Ug))

    if t == 0:
        print("ball_1 a =", round(mag(ball_1.a) / g, 2), "倍g\nball_2 a =", round(mag(ball_2.a) / g, 2), "倍g")
    t += dt