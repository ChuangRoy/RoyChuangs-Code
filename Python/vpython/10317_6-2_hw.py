from vpython import *

A = 2
N = 100
omega = 2*pi*1
T = 2*pi/omega
size = 0.1
m1 = 1
m2 = 2.5
k = 500.0
d = 0.4
turning_point = 75
damp = 0.2

def SpringForce(r):
    return - k*(mag(r))*r/mag(r)

scene = canvas(title='Spring Wave', width=1200, height=300, range = 0.4*50/6, center = vector((N-1)*d/2, 0, 0)) 

ball = []
for i in range(N):
    if i < turning_point:
        ball.append(sphere(radius=size, color=color.yellow, pos=vector(i*d, 0, 0), v=vector(0,0,0), visible = 1))
    else:
        ball.append(sphere(radius=size, color=color.cyan, pos=vector(i*d, 0, 0), v=vector(0,0,0), visible = 1))

spring = [helix(radius = size/2.0, thickness = d/15.0, pos=vector(i*d, 0, 0), axis=vector(d,0,0)) for i in range(N-1)]

t, dt = 0, 0.001

while True:
    rate(1000)
    if t <= T / 2:
        ball[0].pos = vector(0,A*sin(omega*t),0)

    for i in range(N-1):
        spring[i].pos = ball[i].pos
        spring[i].axis = ball[i+1].pos - ball[i].pos

    for i in range(1, N):
        if i == N-1:
            pass
            # x = ball[-1].pos.x
            # ball[-1].v += SpringForce(spring[-1].axis)/m*dt
            # ball[-1].pos += ball[i].v*dt
            # ball[-1].pos.x = x
        else:
            if i < turning_point:
                m = m1
            else:
                m = m2
            AirResistant = -damp * ball[i].v
            ball[i].v += (-SpringForce(spring[i].axis) + SpringForce(spring[i-1].axis) + AirResistant)/m*dt
            ball[i].pos += ball[i].v*dt

    t += dt