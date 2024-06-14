# https://leetcode.com/problems/sqrtx/

class Solution:
    def mySqrt(self, x: int) -> int:
        # NEWTON METHOD
        r = x
        while r * r - x >= 1:
            r = (r + x / r) / 2

        return int(r)

print(Solution().mySqrt(2147395599))
