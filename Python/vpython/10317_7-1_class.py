from vpython import *

# const
A = 0.3
N = 100
size = 0.2
m = 0.1
k = 4000.0
d = 0.4
L = d*(N-1)
t, dt = 0, 0.0005
T = 100*dt
damp = 0.01

def SpringForce(r):
    return - k*(mag(r))*r/mag(r)

if __name__ == "__main__" :
    mu = N*m/L
    Fs = mag(SpringForce(vec(d,0,0)))
    v_wave = sqrt(Fs/mu)
    lambda_wave = 4 * L / 3
    f = v_wave/lambda_wave
    omega = 2*pi*f
    # drawing
    scene = canvas(title='Standing Wave', width=1000, height=300, range = L/6, center = vector((N-1)*d/2, 0, 0))
    ball = [sphere(radius=size, color=color.yellow, pos=vector(i*d, 0, 0), v=vector(0,0,0)) for i in range(N)]
    ball_pos = [vector(i*d,0,0) for i in range(N)]
    ball_v = [vector(0,0,0) for i in range(N)]
    spring_pos = [vector(i*d,0,0) for i in range(N-1)]
    spring_axis = [vector(d,0,0) for i in range(N-1)]
    energy_graph = graph(title="Energy", xtitle="time", ytitle="displacement^2", width=1000, height=250)
    A_curve = gcurve(color=color.orange)

    while True:
        rate(1/dt)
        ball_pos[0] = vector(0, A*sin(omega*t), 0)

        for i in range(N-1):
            spring_pos[i] = ball_pos[i]
            spring_axis[i] = ball_pos[i+1] - ball_pos[i]

        for i in range(1, N):
            if i == N-1:
                # last one
                x = ball_pos[N-1].x
                ball_v[N-1] += (SpringForce(spring_axis[N-2]) - damp*ball_v[N-1])/m*dt
                ball_pos[N-1] += ball_v[N-1]*dt
                ball_pos[N-1].x = x
            else:
                ball_v[i] += (-SpringForce(spring_axis[i]) + SpringForce(spring_axis[i-1]) - damp*ball_v[i])/m*dt
                ball_pos[i] += ball_v[i]*dt

        if t%T+dt > T:
            for i in range(N):
                ball[i].pos = vec(ball_pos[i].x, ball_pos[i].y, ball_pos[i].z)

        scene.center.y = ball[(N-1) // 2].pos.y

        sum_A = 0
        for i in range(N):
            sum_A += ball_pos[i].y**2
        A_curve.plot(t, sum_A)
        t += dt