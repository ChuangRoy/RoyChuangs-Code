import math
counter = 1
running = True
while running:
    try:
        global n
        n = int(input())
    except:
        running = False
        break
    data = ["10:00"]
    for _ in range(n):
        input_d = input().split()
        data.append(input_d[0])
        data.append(input_d[1])
    data.append("18:00")
    nums = []
    for i in data:
        num = int(i[0])*1000 + int(i[1])*100 + int(i[3])*10 + int(i[4])
        nums.append(num)
    numlist = []
    for i in range(0, 2*n+2, 2):
        temp = nums[i+1] // 100 * 60 + nums[i+1] % 100 - nums[i] // 100 * 60 - nums[i] % 100
        numlist.append(temp - nums[i]/2048.0)
    max_d = 0
    for i in numlist:
        if i > max_d:
            max_d = i
    mins = math.ceil(max_d)
    out_time = int((math.ceil(max_d) - max_d) * 2048)
    # print(mins // 100, mins % 100, out_time // 100, ":", out_time % 100)
    print(f"Day #{counter}: the longest nap starts at {out_time // 100}:{(out_time % 100) // 10}{out_time % 10} and will last for ", end='')
    if mins // 60:
        print(f"{mins // 60} hours and ", end='')
    print(f"{mins % 60} minutes.")
    counter += 1