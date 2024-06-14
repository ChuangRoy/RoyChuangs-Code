# https://leetcode.com/problems/pascals-triangle/description/


class Solution:

    def generate(self, numRows):
        ret = []
        for i in range(numRows):
            a = []
            for j in range(i + 1):
                a.append(0)
            a[0] = 1
            a[i] = 1
            if (i - 1 > 0):
                for j in range(1, i):
                    a[j] = ret[i - 1][j - 1] + ret[i - 1][j]
            ret.append(a)
        return ret


print(Solution().generate(10))
