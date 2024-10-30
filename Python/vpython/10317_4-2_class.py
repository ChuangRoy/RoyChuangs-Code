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

scene = canvas(align='left', width=500, height=500, center=vec(0,0,0), background=vec(1,1,1))
earth = sphere(pos=vec(0,0,0), radius=Re, texture=textures.earth)
satellite = sphere(pos=vec(H,0,0), radius=0.5*Re, color=color.red, make_trail=True, retain = 50, v=vec(0,v0,0))
F2 = sphere(pos=vec(0,0,0), radius=Re/3, color=color.red)
line1 = cylinder(radius=Re/10, color=color.black)
line2 = cylinder(radius=Re/10, color=color.black)

gd = graph(align='left', width=500, height=500,
         title='衛星至兩焦點距離和隨時間的關係', xtitle='t/T', ytitle='(PF1 + PF2)/a', ymin = 0,
         foreground=color.black, background=color.white)
f1 = gcurve(color=color.red)
back = False

while mag(satellite.pos - earth.pos) >= Re:
    rate(1000)
    r = satellite.pos - earth.pos
    satellite.a = Fg(r)/m
    satellite.v += satellite.a*dt
    satellite.pos += satellite.v*dt

    K = 0.5 * m * mag(satellite.v) ** 2
    Ug = -G*M*m/mag(r)
    E = K + Ug

    t += dt