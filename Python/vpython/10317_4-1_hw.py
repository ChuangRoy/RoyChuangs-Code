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


while True:
    rate(1000)
    r = satellite.pos - earth.pos
    satellite.a = Fg(r)/m
    satellite.v += satellite.a*dt
    satellite.pos += satellite.v*dt

    if not back and satellite.v.x > 0 and satellite.v.x + satellite.a.x*dt < 0:
        back = True
        Right_pos = vec(satellite.pos.x, satellite.pos.y, satellite.pos.z)
        T = t

        a = mag(Right_pos - Left_pos)/2
        b = mag(Up_pos - Down_pos)/2
        c = sqrt(a**2 - b**2)

        if abs(Right_pos.x) > abs(Left_pos.x):
            F2_pos = earth.pos + vec(2*c,0,0)
            F2.pos = F2_pos
        elif abs(Right_pos.x) < abs(Left_pos.x):
            F2_pos = earth.pos - vec(2*c,0,0)
            F2.pos = F2_pos

    if not back and satellite.v.x < 0 and satellite.v.x + satellite.a.x*dt > 0:
        Left_pos = vec(satellite.pos.x, satellite.pos.y, satellite.pos.z)
    if not back and satellite.v.y > 0 and satellite.v.y + satellite.a.y*dt < 0:
        Up_pos = vec(satellite.pos.x, satellite.pos.y, satellite.pos.z)
    if not back and satellite.v.y < 0 and satellite.v.y + satellite.a.y*dt > 0:
        Down_pos = vec(satellite.pos.x, satellite.pos.y, satellite.pos.z)

    if back:
        line1.pos = earth.pos
        line1.axis = satellite.pos - earth.pos

        line2.pos = F2.pos
        line2.axis = satellite.pos - F2.pos

        f1.plot(pos=(t/T, (mag(line1.axis) + mag(line2.axis))/a))

    t += dt