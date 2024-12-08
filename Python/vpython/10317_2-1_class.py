from vpython import *

g = 9.8
size = 0.5
height = 0
m = 1.0
Fg = vector(0, -m*g, 0)
damp = 0.1

scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0))
floor = box(length=20, height=0.01, width=10, color=color.green)
ball = sphere(radius = size, color=color.yellow, make_trail= True, trail_type="points", interval=100)
ball2 = sphere(radius = size, color=color.red, make_trail= True, trail_type="points", interval=100)

ball.pos = vector(0, height, 0)
ball.v = vector(5, 5, 0)

ball2.pos = vector(0, height, 0)
ball2.v = vector(5, 5, 0)

dt = 0.001
t = 0.0

while t <= 20:
    rate(1000)
    t = t + dt
    AR = - damp * ball2.v
    ball.a = Fg/m
    ball2.a = (Fg+AR)/m
    ball.v += ball.a*dt
    ball.pos += ball.v*dt

    if ball.pos.y <= size and ball.v.y < 0:
        ball.v.y = - ball.v.y

    ball2.v += ball2.a*dt
    ball2.pos += ball2.v*dt

    if ball2.pos.y <= size and ball2.v.y < 0:
        ball2.v.y = - ball2.v.y


print()