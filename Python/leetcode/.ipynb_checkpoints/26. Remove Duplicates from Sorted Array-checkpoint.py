# https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        nums = set(nums)
        nums = list(nums)
        return len(nums)
        
print(Solution.removeDuplicates(Solution, [1,1,2]))