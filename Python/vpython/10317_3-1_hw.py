from vpython import *

g = vector(0,-9.8,0)
size = 0.8
k = 100
m1 = 5.0
m2 = 5.0
d = 15*size

def SpringForce(r,L):
    return -k*(mag(r)-L)*r/mag(r)


scene = canvas(width=600, height=600, center = vector(d/2,1.5*d,0), background = vector(1,1,1), range=25)

spring = helix(radius = size/2, coils = 15, color = color.black, thickness = size/5)
ball_1 = sphere(radius = size, color=color.blue, make_trail=True)
ball_2 = sphere(radius = size, color=color.green, make_trail=True)
ball_cm = sphere(radius = size/3, color=color.red, make_trail=True)
ball_1.pos = vector(0, size, 0)
ball_2.pos = vector(d, size, 0)
ball_1.v = vector(20, 40, 0)
ball_2.v = vector(-1, 0, 0)

spring.pos = ball_1.pos
spring.axis = ball_2.pos - ball_1.pos

t = 0
dt = 0.001
while True:
    rate(1/dt)
    ball_1.v += (m1*g - SpringForce(spring.axis, d))/m1*dt
    ball_1.pos = ball_1.pos + ball_1.v*dt
    spring.pos = ball_1.pos
    spring.axis = ball_2.pos - ball_1.pos
    ball_cm.pos = spring.pos + spring.axis / 2
    ball_2.v += (m2*g + SpringForce(spring.axis, d))/m2*dt
    ball_2.pos = ball_2.pos + ball_2.v*dt