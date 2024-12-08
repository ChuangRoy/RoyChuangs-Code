from vpython import *
import time

g = 9.8
size = 0.5
height = 0
m = 1.0
Fg = vector(0, -m*g, 0)
damp = 0.1

scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0))
floor = box(length=20, height=0.01, width=10, color=color.green)
ball = sphere(radius = size, color=color.yellow, make_trail = True, trail_type="points", interval=1)


theta_t_plot = graph(title = "theta t plot", width=600, height=400, xtitle="theta", ytitle="t")
theta_t_plot = gcurve(color=color.blue)

theta_r_plot = graph(title = "theta r plot", width=600, height=400, xtitle="theta", ytitle="R")
theta_r_plot = gcurve(color=color.red)

v0 = 20
text = label(pos=vector(0,-7*size,0), box = False, height = 20, color=color.cyan)
for i in range(0, 183, 3):
    theta = i * pi / 180
    text.text = f'theta={i}'
    dt = 0.001
    t = 0.0
    ball.pos = vector(0, 0, 0)
    ball.make_trail = True
    ball.v = vector(v0*cos(theta), v0*sin(theta), 0)
    while ball.pos.y >= 0 or ball.v.y > 0:
        rate(4000)
        t += dt
        ball.a = Fg / m
        ball.v += ball.a*dt
        ball.pos += ball.v*dt
    theta_t_plot.plot(pos=(i, t))
    theta_r_plot.plot(pos=(i, ball.pos.x))
    print(f"T = {t}, R = {ball.pos.x}, theta = {i} \n", end='')
    time.sleep(0.1)
print()
