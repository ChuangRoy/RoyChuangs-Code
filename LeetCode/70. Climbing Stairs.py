# https://leetcode.com/problems/climbing-stairs/

class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n // 2 + 1
        else:
            return n



print(Solution.climbStairs(5))
