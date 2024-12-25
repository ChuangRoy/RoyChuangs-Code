from vpython import*

N = 5
m = [1, 1, 1, 1, 1]
x = [-15, -10, 0, 5, 10]
v = [7, 7, 0, 0, 0]
size = 2
k = 3      
t = 0      
dt = 0.001 


def ElasticCollision(v1, v2, r1, r2, m1, m2):  
    v1_col = v1 - (2*m2/(m1+m2)) * dot((v1-v2), (r1-r2)) * (r1-r2)/mag(r1-r2)**2
    v2_col = v2 - (2*m1/(m1+m2)) * dot((v2-v1), (r2-r1)) * (r2-r1)/mag(r2-r1)**2 
    return (v1_col, v2_col)


scene = canvas(width=800, height=250, background=vec(1,1,1), center=vec(5,0,10), 
               forward=vec(0,0,-1), range=15, fov=0.004)
ball = [sphere(pos=vec(x[i],0,0), v=vec(v[i],0,0), a=vec(0,0,0), radius=size, color=color.blue) for i in range(N)]
v_arrow = [arrow(pos=ball[i].pos, axis=ball[i].v, color=color.blue) for i in range(N)]


energy_graph = graph(title="Energy vs Time", xtitle="Time (s)", ytitle="Energy (J)", ymin=0, width=800, height=250)
K_curve = gcurve(color=color.orange, label="Kinetic Energy")

while True:
    rate(1/dt)
    K = 0
    for i in range(N):
        ball[i].pos += ball[i].v * dt
        for j in range(N):
            if i != j and mag(ball[i].pos - ball[j].pos) <= 2*size and dot(ball[i].pos-ball[j].pos, ball[i].v-ball[j].v) < 0:
                ball[i].v , ball[j].v = ElasticCollision(ball[i].v, ball[j].v, ball[i].pos, ball[j].pos, m[i], m[j])

        v_arrow[i].pos = ball[i].pos
        v_arrow[i].axis = ball[i].v
        K += 0.5*m[i]*mag(ball[i].v)**2

    K_curve.plot(t, K)

    t += dt
