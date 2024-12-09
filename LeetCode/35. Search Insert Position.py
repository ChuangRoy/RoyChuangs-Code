# https://leetcode.com/problems/search-insert-position/

class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        l = 0
        h = len(nums) - 1
        while l <= h:
            m = (l + h) // 2
            if nums[m] == target:
                return m
            if nums[m] > target:
                h = m - 1
            if nums[m] < target:
                l = m + 1
        if l > m:
            return m+1
        if h < m:
            return m

print(Solution.searchInsert(Solution(), [1, 3, 5, 6], 4))
