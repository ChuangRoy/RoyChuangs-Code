# https://leetcode.com/problems/remove-element/

class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                nums.pop(i)
            else:
                i += 1

print(Solution.removeElement(Solution(), [3,2,2,3], 3))