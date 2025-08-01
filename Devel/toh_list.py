layers = 8
counter = 0
toh = []
for x in range(layers):
    toh.append([1, 'a', 'b', 'c'])
i = 0
if layers <= 0:
    i = -1
while i >= 0:
    if i == layers - 1:
        print("Disk", layers - i, toh[i][1], "->", toh[i][3])
        counter += 1
        i -= 1
    else:
        if toh[i][0] == 1:
            toh[i+1][0] = 1
            toh[i+1][1] = toh[i][1]
            toh[i+1][2] = toh[i][3]
            toh[i+1][3] = toh[i][2]
            toh[i][0] = 2
            i += 1
        elif toh[i][0] == 2:
            counter += 1
            print("Disk", layers - i, toh[i][1], "->", toh[i][3])
            toh[i][0] = 0
            toh[i+1][0] = 1
            toh[i+1][1] = toh[i][2]
            toh[i+1][2] = toh[i][1]
            toh[i+1][3] = toh[i][3]
            i += 1
        else:
            i -= 1
print(counter)
