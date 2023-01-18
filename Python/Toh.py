
## Start From Scratch !
## Create animation

import tkinter as tk
import tkinter.ttk as ttk

class Toh:
    def __init__ (self, x, a, b, c):
        self.x = x
        self.a = a
        self.b = b
        self.c = c
        self.counter = 1
        self.Toh_List = {self.a:[], self.b:[], self.c:[]}
        self.create_toh_list(self.a, self.x)
        self.Toh(self.x, self.a, self.b, self.c)

    def create_toh_list (self, a, x):
        toh_list = self.Toh_List [a]
        toh_list.append(None)
        for i in range (x):
            toh_list.append(i)

    def Toh (self, x, start, rest, finish):
        if x == 1:
            print(f"{self.counter}: Disk {x} from {start} to {finish}")
            self.counter = self.counter + 1
            # Move Disk 1 from start to finish
        else:
            self.Toh(x-1, start, finish, rest)
            
            print(f"{self.counter}: Disk {x} from {start} to {finish}")
            self.counter = self.counter + 1
            
            self.Toh(x-1, rest, start, finish)
        
toh = Toh(8, "a", "b", "c")
