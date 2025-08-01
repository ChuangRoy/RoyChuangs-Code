x = int(input())
for _ in range(x):
    a = input()
    for k in a:
        if (k == '貓'):
            print("喵", end='')
        else:
            print(k, end='')
    print(end='\n')
