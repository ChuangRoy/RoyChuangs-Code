from vpython import*

N = 12
m = [1 for i in range(N)]
colors = [color.blue, color.red]
w = 25
v_scale = 20
v_list = [vec(v_scale*random()-v_scale/2, v_scale*random()-v_scale/2, 0) for i in range(N)]
pos_list = [vec(w*random()-w/2, w*random()-w/2, 0) for i in range(N)]

size = [1.2 for i in range(N)]
k = 3
t = 0
dt = 0.001

def ElasticCollision(v1, v2, r1, r2, m1, m2):  
    v1_col = v1 - (2*m2/(m1+m2)) * dot((v1-v2), (r1-r2)) * (r1-r2)/mag(r1-r2)**2
    v2_col = v2 - (2*m1/(m1+m2)) * dot((v2-v1), (r2-r1)) * (r2-r1)/mag(r2-r1)**2 
    return (v1_col, v2_col)


scene = canvas(width=500, height=500, background=vec(1,1,1), center=vec(0,0,0), forward=vec(0,0,-1), range=15, fov=0.004, align='left')
ball = [sphere(pos=pos_list[i], v=v_list[i], a=vec(0,0,0), radius=size[i], color=colors[i%2]) for i in range(N)]
v_arrow = [arrow(pos=ball[i].pos, axis=ball[i].v, color=colors[i % 2], opacity=0.3) for i in range(N)]

energy_graph = graph(title="Energy vs Time", xtitle="Time (s)", ytitle="Energy (J)", ymin=0, width=800, height=250, align='left')
K_curve = gcurve(color=color.orange, label="Kinetic Energy")

# down left up right
# length:x width:z height:y
walls_size_list = [[w, 0.1, 0.1], [0.1, 0.1, w]]
walls_pos_list = [vec(0, -w/2, 0), vec(-w/2, 0, 0), vec(0, w/2, 0), vec(w/2, 0, 0)]
walls = [box(pos=walls_pos_list[i], length = walls_size_list[i%2][0], width=walls_size_list[i%2][1],
         height=walls_size_list[i%2][2], color=color.black, opacity=1) for i in range(4)]

while True:
    rate(1/dt)
    K = 0
    for i in range(N):
        ball[i].pos += ball[i].v * dt
        for j in range(N):
            if i != j and mag(ball[i].pos - ball[j].pos) <= 2*size[i] and dot(ball[i].pos-ball[j].pos, ball[i].v-ball[j].v) < 0:
                ball[i].v , ball[j].v = ElasticCollision(ball[i].v, ball[j].v, ball[i].pos, ball[j].pos, m[i], m[j])

        v_arrow[i].pos = ball[i].pos
        v_arrow[i].axis = ball[i].v

        # down left up right
        if ball[i].pos.y <= walls_pos_list[0].y + size[i] and ball[i].v.y < 0: # down
            ball[i].v.y = -ball[i].v.y
        if ball[i].pos.y >= walls_pos_list[2].y - size[i] and ball[i].v.y > 0: # up
            ball[i].v.y = -ball[i].v.y
        if ball[i].pos.x <= walls_pos_list[1].x + size[i] and ball[i].v.x < 0: # left
            ball[i].v.x = -ball[i].v.x
        if ball[i].pos.x >= walls_pos_list[3].x - size[i] and ball[i].v.x > 0: # right
            ball[i].v.x = -ball[i].v.x
    
        K += 0.5*m[i]*mag(ball[i].v)**2

    K_curve.plot(t, K)

    t += dt
