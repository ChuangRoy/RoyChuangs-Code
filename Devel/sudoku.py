def check_if_ok (x, y):
    global puzzle
    ok = 1
    for i in range (9):
        if (puzzle[y][i] == puzzle[y][x]) and (i != x):
            ok = 0 # not ok
    if ok:
        for i in range (9):
            if (puzzle[i][x] == puzzle[y][x]) and (i != y):
                ok = 0
    if ok: # block
        top_x, top_y = x-x%3, y-y%3
        for i in range(top_x, top_x+3):
            for j in range(top_y, top_y+3):
                if (puzzle[j][i] == puzzle[y][x]) and (i != x) and (j != y):
                    ok = 0
    # print (x, y, " right")
    return ok


puzzle = [[0,5,7,0,0,0,0,0,0],
          [2,0,0,4,0,8,0,3,0], 
          [0,1,0,0,0,0,0,0,9],
          [0,0,0,0,0,9,1,0,5],
          [0,0,5,0,6,0,3,0,0],
          [3,0,4,8,0,0,0,0,0],
          [5,0,0,0,0,0,0,8,0],
          [0,7,0,6,0,2,0,0,3],
          [0,0,0,0,0,0,2,5,0]]
          
# Scan Blanks
Blanks = list()
for row in range(9):
    for col in range(9):
        if puzzle [row][col] == 0:
            Blanks.append((col, row))
            
##print(Blanks)
unknowns = len(Blanks)
step = 0
counter = 0
while step < unknowns and step >= 0:
    cell_x, cell_y = Blanks [step]
    if puzzle [cell_y][cell_x] == 9:
        step -= 1
        puzzle [cell_y][cell_x] = 0
    else:
        counter += 1
        puzzle [cell_y][cell_x] += 1
        if check_if_ok (cell_x, cell_y): # right
            step += 1
##            print("step", step, "at", cell_x, cell_y
##                    , "guess", puzzle [cell_y][cell_x])

for i in range (9):
    if i%3 == 0:
        print("-------------")
    for j in range (9):
        if j%3 == 0:
            print("|", end='')
        print(puzzle[i][j], end='')
    print("|")
print("-------------")

print ("Guessed", counter, "times")
