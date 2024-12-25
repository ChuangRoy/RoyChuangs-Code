from vpython import *

g = 9.8
size = 0.5
height = 2.5
m = 1.0
Fg = vector(0, -m*g, 0)
damp = 0.1

scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0))
floor = box(length=20, height=0.01, width=10, color=color.green)
ball = sphere(radius = 0.749/(2*pi), color=color.yellow, make_trail = True, trail_type="points", interval=1)


# 選擇三分線作為出手位置
basket = ring(pos=vec(6.35, 3.05, 0), axis=vec(0, 1, 0), radius = (0.4572)/2, thickness = 0.016, color=color.red)

text = label(pos=vector(0,-7*size,0), box = False, height = 20, color=color.cyan)
for v0 in range(5, 16):
    for i in range(45, 91):
        theta = i * pi / 180
        dt = 0.001
        t = 0.0
        ball.pos = vector(0, height, 0)
        ball.make_trail = False
        ball.v = vector(v0*cos(theta), v0*sin(theta), 0)
        text.text = f'v0={v0}\ntheta={i}'
        while ball.pos.y >= 0 or ball.v.y > 0:
            rate(8000)
            t += dt
            ball.a = Fg / m
            ball.v += ball.a*dt
            ball.pos += ball.v*dt
            if 6.45 >= ball.pos.x and ball.pos.x >= 6.24:
                if (ball.pos.y >= basket.pos.y) and (ball.pos.y + ball.v.y*dt <= basket.pos.y):
                    print(f"In v0={v0} deg={i}")