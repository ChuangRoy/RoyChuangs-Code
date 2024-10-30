from vpython import*	#引用視覺畫套件Vpython

size = 0.05	#設定球的大小為0.05公尺

x = arrow(pos=vector(0,0,0), axis=vector(1,0,0), shaftwidth=0.02, color=color.green)
y = arrow(pos=vector(0,0,0), axis=vector(0,1,0), shaftwidth=0.02, color=color.red)
z = arrow(pos=vector(0,0,0), axis=vector(0,0,1), shaftwidth=0.02, color=color.blue)
#畫出3D直角座標沿x,y,z方向的單位向量

ball = sphere(radius=size, color=color.yellow, pos=vector(0,0,0), v=vector(0.0,0,0), a=vector(5.0, 0, 0))
#畫球，球的半徑為size，顏色為黃色，位置在(0,0,0)，速度為(1,0,0)

t = 0		#設定模擬的初始時間
fps = 1024
dt = float(1/fps)	#模擬的時間間隔

xt = graph(title = "x-t plot", width=600, height=400, xtitle="t", ytitle="x")
#設定函數圖的畫面
fxt = gcurve(color=color.blue)  	#設定函數圖中線條的特性，這裡只設定顏色

vt = graph(title = "v-t plot", width=600, height=400, xtitle="t", ytitle="v")
#設定函數圖的畫面
fvt = gcurve(color=color.green)  	#設定函數圖中線條的特性，這裡只設定顏色

at = graph(title = "a-t plot", width=600, height=400, xtitle="t", ytitle="a")
#設定函數圖的畫面
fat = gcurve(color=color.red)  	#設定函數圖中線條的特性，這裡只設定顏色

max_x = 0
    
while t < 6 * fps:          #條件判斷t<2成立時執行迴圈內容
    rate(fps)      #設定迴圈的執行速度，每秒執行1/dt次
    t = t + 1        #計時器
    ball.pos = ball.pos + ball.v*dt  #球的每一時刻位置，每次迴圈改變ball.v *dt的位移
    ball.v = ball.v + ball.a*dt
    fxt.plot(pos=(t / fps, ball.pos.x))	#每一個迴圈畫一個點描出線條，x軸為時間，y軸為位置
    fvt.plot(pos=(t / fps, ball.v.x))
    fat.plot(pos=(t / fps, ball.a.x))

    if ball.pos.x > max_x:
        max_x = ball.pos.x
        max_x_t = t / fps

    if (round(t / fps, 3) <= 2.0):
        ball.a.x = 5
    else:
        ball.a.x = -5

    # print (t)       #在執行視窗印出每一時刻的時間
print("turning point:", end='')
print(round(max_x, 3))
print("occur at t:", round(max_x_t, 3))
print()