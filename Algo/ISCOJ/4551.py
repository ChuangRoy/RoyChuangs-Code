def foo (a):
    if a == 1:
        return a
    else:
        b = a - 1
        c = foo(b)
        d = c * a
        return d

x = int(input())
for i in range(x):
    e = int(input())
    print(foo(e))