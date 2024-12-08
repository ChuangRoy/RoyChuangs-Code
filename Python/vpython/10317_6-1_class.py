from vpython import *

g = 9.8
k = 80.0
L0 = 0.6
H = 1.5
m = 0.5
d = 0.15
size = 0.06
n = 40
T = 0.05

scene = canvas(width=800, height=400, center=vector(d*n/2-d/2,L0,0))
floor = box(length=d*n, height=0.005, width=0.3, color=color.yellow, pos=vector(d*n/2-d/2,0,0))

def SpringForce(r,L):
    return -k*(mag(r)-L)*r/mag(r)

dt = 0.001
t = 0.0

ball = []
spring = []
for i in range(0,n,1):
    ball.append(sphere(radius=size, color=color.red, pos=vec(i*d,H,0), v=vector(0, 0, 0)))
    spring.append(helix(radius=0.03, thickness=0.01, pos=vec(i*d,0,0), axis=vector(0,L0,0)))

touched = [False] * n

while True:
    rate(1/dt/3)
    
    a = []
    for i in range(n):
        if t < i*T: a.append(vector(0,0,0))
        else: a.append(vector(0,-g,0))
        if ball[i].pos.y - spring[i].pos.y - spring[i].axis.y <= size:
            touched[i] = True
        if touched[i]:
            spring[i].axis = ball[i].pos - spring[i].pos - vector(0,size,0)

        a[i] = a[i] + SpringForce(spring[i].axis,L0)/m
        ball[i].v = ball[i].v + a[i]*dt
        ball[i].pos = ball[i].pos + ball[i].v*dt
    
    t = t + dt