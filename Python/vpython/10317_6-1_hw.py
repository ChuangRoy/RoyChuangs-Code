from vpython import *

g = 9.8
theta = 10*pi/180
k = 100000
m = 1.0
n = 12
d = 0.1
size = d/3.5
T0 = 1
N = 16
T = N * T0

def calStrL (t):
    temp = t / (2 * pi)
    temp = temp ** 2
    return temp * g

L = []
for i in range(N, N - n - 1, -1):
    L.append(calStrL(T / i))
print(L)

def SpringForce(r,L):
    return - k*(mag(r)-L) * r / mag(r)

scene = canvas(width=600, height=800,center = vector(0, -L[n-1]/2-d, d*n/2+0.15), range=0.9)     
ceiling = box(pos=vector(0,0,(n-1)*d/2), length=0.03, height=0.001, width=(n-1)*d*1.01, color=vector(0.7,0.7,0.7))    
timer = label(pos=vector(5*d,2*d,d*n/2), box = False, height = 20, color=color.yellow)

ball = []
string = []
for i in range(0,n,1):
    ball.append(sphere(pos=vector(L[i]*sin(theta), -L[i]*cos(theta), d*i), v=vector(0,0,0), radius=size, color=color.yellow))
    string.append(cylinder(pos=vector(0,0,d*i), color=vector(0.7,0.7,0.7), radius=0.001))

dt = 0.001
t = 0
while True:
    rate(1/dt)
    Timer = round((t%T) / T0, 2)
    timer.text = str('Time of the longest is T0 :\n T = ') + str(Timer) + str("T0")

    a = []
    for j in range(0,n,1):
        string[j].axis = ball[j].pos - string[j].pos
        a.append(vector(0,-g,0)+SpringForce(string[j].axis, L[j])/m)
        ball[j].v += a[j]*dt
        ball[j].pos += ball[j].v*dt

    t = t+dt
