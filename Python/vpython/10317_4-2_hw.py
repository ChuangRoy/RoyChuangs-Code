from vpython import *

G = 6.67*10**(-11)
M = 6*10**24
m = 1000
Re = 6.4*10**6
H = 20*Re
t = 0
dt = 30
v0 = 1200

def Fg(r):
    return -G*M*m/mag(r)**2 * r/mag(r)

scene = canvas(align='left', width=500, height=500, center=vec(0,0,0), background=vec(1,1,1))
earth = sphere(pos=vec(0,0,0), radius=Re, texture=textures.earth)
satellite = sphere(pos=vec(H,0,0), radius=0.5*Re, color=color.red, make_trail=True, v=vec(0,v0,0))

back = False

while mag(satellite.pos - earth.pos) >= Re:
    rate(5000)
    satellite.a = Fg(satellite.pos - earth.pos)/m
    satellite.v += satellite.a*dt
    satellite.pos += satellite.v*dt

    if satellite.v.x > 0 and satellite.v.x + satellite.a.x*dt < 0:
        back = 1
        Right_pos = vec(satellite.pos.x, satellite.pos.y, satellite.pos.z)
        a = mag(Right_pos - Left_pos)/2
        T = t
        K_earth = pow(a, 3) / pow(T, 2)
        satellite.v.y += 100
        print(K_earth)
        t = 0

    if satellite.v.x < 0 and satellite.v.x + satellite.a.x*dt > 0:
        Left_pos = vec(satellite.pos.x, satellite.pos.y, satellite.pos.z)

    t += dt