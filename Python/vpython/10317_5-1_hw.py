from vpython import*

m = [0.1, 0.5, 3] 
N = 3
y = [18, 14.5, 9]
v = [0, 0, 0]
size = [1, 2, 3]

ball_color = [color.red, color.orange, color.yellow, color.green, color.blue, color.magenta, color.purple]
k = 500       
t = 0        
dt = 0.0002
g = vec(0, -10, 0)

def Fs(r,L):
    return - k*(mag(r)-L) * r/mag(r)


scene = canvas(width=250, height=600, background=vec(1,1,1), center=vec(0,60,10), forward=vec(0,0,-1), range=30, fov=0.004, align='left')
ground = box(pos=vec(0,0,0), length = 30, width=30, height=0.1, color=vec(0.5,0.5,0.5), opacicy=1)
ball = [sphere(pos=vec(0, y[i], 0), v=vec(0, 0 ,0), a=vec(0, 0, 0), radius=size[i], color=ball_color[i%7]) for i in range(N)]

energy_graph = graph(title="Energy vs Time", xtitle="Time (s)", ytitle="Energy (J)", width=600, height=250, align='left')
E_curve = gcurve(color=color.black, label="Mechanical Energy")
K_curve = gcurve(color=color.orange, label="Kinetic Energy")
Us_curve = gcurve(color=color.red, label="Spring Potential Energy")
Ug_curve = gcurve(color=color.blue, label="Gravatational Potential Energy")


while True:
    rate(1/dt)

    Us = 0
    K = 0
    Ug = 0
    for i in range(N):  
        force = vec(0,0,0)   
        for j in range(N):  
            r = ball[j].pos - ball[i].pos
            L = size[i] + size[j]
            if i!=j and mag(r) <= size[i] + size[j]:
                force += -Fs(r, L)
                Us += 0.25*k*(mag(r)-size[i]-size[j])**2

        ball[i].a = force/m[i] + g
        ball[i].v += ball[i].a*dt
        ball[i].pos += ball[i].v*dt  
        Ug += m[i] * mag(g) * ball[i].pos.y
        K += 0.5 * m[i]*(mag(ball[i].v) ** 2)
        if ball[i].pos.y <= size[i] and ball[i].v.y < 0:
            ball[i].v.y = -ball[i].v.y


    E = K + Us + Ug
    E_curve.plot(t, E)
    K_curve.plot(t, K)
    Us_curve.plot(t, Us)
    Ug_curve.plot(t, Ug)

    t += dt
