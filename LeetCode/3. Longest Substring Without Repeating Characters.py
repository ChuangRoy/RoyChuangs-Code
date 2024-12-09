# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:    # Solution By: https://www.youtube.com/watch?v=wiGpQwVHdE0
        charSet = set()
        l = 0
        res = 0
        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            res = max(res, r - l + 1)
        
        return res
                

sol = Solution()
print(sol.lengthOfLongestSubstring("pwwkew"))