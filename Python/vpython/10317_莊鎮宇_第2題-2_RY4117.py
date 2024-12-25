from vpython import *

# G = 6.67*10**(-11)
G = 1
M = 10000
m = 1
Re = 10
H = 10*Re
t = 0
dt = 0.1

v0 = 15

def Fg(r):
    return -G*M*m/mag(r)**2 * r/mag(r)

scene = canvas(align='left', width=500, height=500, center=vec(0,0,0), background=vec(0.6,0.8,0.8))
earth = sphere(pos=vec(0,0,0), radius=Re)
earth.v = vec(0, v0, 0)
satellite = sphere(pos=vec(H,0,0), radius=10, color=color.red, make_trail=True, retain=50)
satellite.v = vec(-v0 / 1.4,v0 / 1.4,0)

gd = graph(align='left', width=500, height=500,
            title='v-t graph', xtitle='t',
            foreground=color.black, background=color.white)
f1 = gcurve(color=color.red)

F0 = G*M*m/Re**2

while mag(satellite.pos - earth.pos) >= Re:
    rate(1000)
    r = satellite.pos - earth.pos
    satellite.a = Fg(r)/m
    satellite.v += satellite.a*dt
    satellite.pos += satellite.v*dt

    f1.plot(pos=(t, mag(satellite.v)))
    t += dt