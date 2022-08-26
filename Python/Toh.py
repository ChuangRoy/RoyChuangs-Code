# a = int(input())
# def ToH(n , A, B, C, i):
    # if n == 1:
        # i = i + 1
        # print(i, " Disk 1 from",A,"to",B)
        # return i
    # i = ToH(n-1, A, C, B, i)
    # i = i + 1
    # print(i, " Disk",n,"from",A,"to",B)
    # i = ToH(n-1, C, B, A, i)
    # return i
          
# ToH(a,'A','B','C', 0)


## Start From Scratch !
counter = 1

def Toh (x, start, rest, finish):
    global counter
    if x == 1:
        print(f"{counter}: Disk {x} from {start} to {finish}")
        counter += 1
        # Move Disk 1  from start to finish
    else:
        Toh(x-1, start, finish, rest)
        print(f"{counter}: Disk {x} from {start} to {finish}")
        counter += 1
        Toh(x-1, rest, start, finish)
        
Toh(8, "a", "b", "c")