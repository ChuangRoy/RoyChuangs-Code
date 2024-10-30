from vpython import*	#引用視覺畫套件Vpython

size = 0.05	#設定球的大小為0.05公尺

x = arrow(pos=vector(0,0,0), axis=vector(1,0,0), shaftwidth=0.02, color=color.green)
y = arrow(pos=vector(0,0,0), axis=vector(0,1,0), shaftwidth=0.02, color=color.red)
z = arrow(pos=vector(0,0,0), axis=vector(0,0,1), shaftwidth=0.02, color=color.blue)
#畫出3D直角座標沿x,y,z方向的單位向量

ball = sphere(radius=size, color=color.yellow, pos=vector(0,0,0), v=vector(3.0,0,0), a=vector(-1.0, -0.5, 0))
#畫球，球的半徑為size，顏色為黃色，位置在(0,0,0)，速度為(1,0,0)

t = 0		#設定模擬的初始時間
fps = 1024
dt = float(1/fps)	#模擬的時間間隔


xt = graph(title = "x-t plot", width=600, height=400, xtitle="t", ytitle="x")
fxt = gcurve(color=color.black)  	#設定函數圖中線條的特性，這裡只設定顏色

vxt = graph(title = "vx-t plot", width=600, height=400, xtitle="t", ytitle="v-x")
fvxt = gcurve(color=color.blue)  	#設定函數圖中線條的特性，這裡只設定顏色
vyt = graph(title = "vy-t plot", width=600, height=400, xtitle="t", ytitle="v-y")
fvyt = gcurve(color=color.green)  	#設定函數圖中線條的特性，這裡只設定顏色
vzt = graph(title = "vz-t plot", width=600, height=400, xtitle="t", ytitle="v-z")
fvzt = gcurve(color=color.red)  	#設定函數圖中線條的特性，這裡只設定顏色

max_x = 0
max_t = 0
s = 4
    
while t <= fps * s:
    rate(fps)
    t = t + 1        #計時器
    ball.pos = ball.pos + ball.v*dt  #球的每一時刻位置，每次迴圈改變ball.v *dt的位移
    ball.v = ball.v + ball.a*dt
    fxt.plot(pos=(t / fps, ball.pos.x))
    fvxt.plot(pos=(t / fps, ball.v.x))
    fvyt.plot(pos=(t / fps, ball.v.y))
    fvzt.plot(pos=(t / fps, ball.v.z))
    if (ball.pos.x >= max_x):
        max_x = ball.pos.x
        max_t = t


    if (t % 409 == 0):
        v_arrow = arrow(pos=ball.pos, axis=ball.v, shaftwidth=0.02, color=color.green)
        a_arrow = arrow(pos=ball.pos, axis=ball.a, shaftwidth=0.02, color=color.red)
        sphere(color=color.orange, pos=ball.pos, radius=size)                  #畫球

    # print (t)       #在執行視窗印出每一時刻的時間


print("x max", max_x)
print("t:", max_t / 1024)
print()