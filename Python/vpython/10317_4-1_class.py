from vpython import *

G = 6.67*10**(-11)
M = 6*10**24
m = 1000
Re = 6.4*10**6
H = 20*Re
t = 0
dt = 60

v0 = 1200

def Fg(r):
    return -G*M*m/mag(r)**2 * r/mag(r)

scene = canvas(align='left', width=500, height=500, center=vec(0,0,0), background=vec(0.6,0.8,0.8))
earth = sphere(pos=vec(0,0,0), radius=Re, texture=textures.earth)
satellite = sphere(pos=vec(H,0,0), radius=0.5*Re, color=color.red, make_trail=True, retain=50)
satellite.v = vec(0,v0,0)

gd = graph(align='left', width=500, height=500,
            title='E:red K:green Ug:blue', xtitle='t',
            foreground=color.black, background=color.white)
f1 = gcurve(color=color.red)
f2= gcurve(color=color.green)
f3= gcurve(color=color.blue)
F0 = G*M*m/Re**2

while mag(satellite.pos - earth.pos) >= Re:
    rate(1000)
    r = satellite.pos - earth.pos
    satellite.a = Fg(r)/m
    satellite.v += satellite.a*dt
    satellite.pos += satellite.v*dt


    K = 0.5 * m * mag(satellite.v) ** 2
    Ug = -G*M*m/mag(r)
    E = K + Ug
    f1.plot(pos=(t, E))
    f2.plot(pos=(t, K))
    f3.plot(pos=(t, Ug))
    t += dt