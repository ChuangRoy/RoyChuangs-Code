# https://leetcode.com/problems/pascals-triangle-ii/

class Solution:
    def getRow(self, rowIndex: int):
        all = []
        for i in range(rowIndex+1):
            a = []
            for j in range(i + 1):
                a.append(0)
            a[0] = 1
            a[i] = 1
            if (i - 1 > 0):
                for j in range(1, i):
                    a[j] = all[i - 1][j - 1] + all[i - 1][j]
            all.append(a)
        return all[rowIndex]
        
print(Solution.getRow(0, 3))