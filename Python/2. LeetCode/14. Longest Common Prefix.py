# https://leetcode.com/problems/longest-common-prefix/

class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        prefix = strs[0]
        for i in strs:
            j = 0
            while j < len(i) and j < len(prefix) and i[j] == prefix[j]:
                j += 1
            prefix = i[:j]
            
        return prefix
            
            
        
sol = Solution()
print(sol.longestCommonPrefix(["dog","racecar","car"]))