# https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a = nums1 + nums2
        a.sort()
        if len(a) % 2 == 0:
            median_index = len(a) // 2 - 1
            median = float(a[median_index] + a[median_index + 1]) / 2
        else:
            median_index = int(len(a) / 2)
            median = a[median_index]
        return median
        
sol = Solution()
print(sol.findMedianSortedArrays([1,2], [3,4]))
