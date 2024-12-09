# https://leetcode.com/problems/add-binary/

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a_int = 0
        b_int = 0
        for i in range(len(a)):
            j = len(a) - i - 1
            a_int += (int(a[j])*(2**i))
        for i in range(len(b)):
            j = len(b) - i - 1
            b_int += (int(b[j])*(2**i))
        ret = format(a_int + b_int, "b")
        return ret


print(Solution.addBinary(Solution(), "11", "1"))
