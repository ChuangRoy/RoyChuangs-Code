from vpython import*

m = [1, 1, 1, 1, 1, 1, 1] 
N = len(m)
x = [-20, -17, -5, -2, 1, 5, 10]
v = [5, 5, 0, 0, 0, 0, 0]      

ball_color = [color.red, color.orange, color.yellow, color.green, color.blue, color.magenta, color.purple]
size = 1.2   
k = 500       
t = 0        
dt = 0.0002

def Fs(r): 
    return - k*(mag(r)-2*size) * r/mag(r)


scene = canvas(width=800, height=250, background=vec(1,1,1), center=vec(5,0,10), 
               forward=vec(0,0,-1), range=10, fov=0.004)

ball = [sphere(pos=vec(x[i], 0, 0), v=vec(v[i], 0 ,0), a=vec(0, 0, 0), radius=size, color=ball_color[i%7]) for i in range(N)]
v_arrow = [arrow(pos=ball[i].pos, axis=ball[i].v, color=ball[i].color) for i in range(N)]


energy_graph = graph(title="Energy vs Time", xtitle="Time (s)", ytitle="Energy (J)", width=800, height=250)
E_curve = gcurve(color=color.black, label="Mechanical Energy")
K_curve = gcurve(color=color.orange, label="Kinetic Energy")
Us_curve = gcurve(color=color.red, label="Potential Energy")

# sleep(100)

while True:
    rate(1/dt)

    Us = 0
    K = 0
    for i in range(N):  #第1層迴圈
        force = vec(0,0,0)   #每次歸零第1層迴圈的作用力
        for j in range(N):  #第2層迴圈
            r = ball[j].pos - ball[i].pos  #任意兩球的距離向量
            if i!=j and mag(r) <= size*2:  #排除i、j具有相同編號的球，且球心距離小於球半徑和時計算彈力
                force += -Fs(r)   #計算第i個球以外的所有球對其作用的總彈力
                Us += 0.25*k*(mag(r)-2*size)**2   #計算所有球之間的彈力位能
        
        
        v_arrow[i].pos = ball[i].pos #更新速度箭頭位置
        v_arrow[i].axis = ball[i].v  #更新速度箭頭軸方向
        
        ball[i].a = force/m[i] #將合力計算結果指派給加速度
        ball[i].v += ball[i].a*dt    #更新球的速度
        ball[i].pos += ball[i].v*dt  #更新球的位置
        
        K += 0.5 * m[i]*(mag(ball[i].v) ** 2)
        
    E = K + Us  
    E_curve.plot(t, E)
    K_curve.plot(t, K)
    Us_curve.plot(t, Us)

    t += dt
    