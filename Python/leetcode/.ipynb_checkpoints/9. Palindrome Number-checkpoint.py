# https://leetcode.com/problems/palindrome-number/
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            str_x = str(x)
            for i in range(x // 2 + x % 2):
                if str_x[x] != str_x[len(str_x) - x]:
                    return False
            return True

sol = Solution()
print(sol.isPalindrome(121))
