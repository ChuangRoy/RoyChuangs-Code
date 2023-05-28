# https://leetcode.com/problems/plus-one/

class Solution:
        def plusOne(self, digits: list[int]) -> list[int]:
            a = 1
            # for i in range(len(digits)-1, 0):
            for i in range(len(digits)):
                j = len(digits) - i - 1
                temp = (digits[j] + a) // 10
                digits[j] = (digits[j] + a) % 10
                a = temp

            if a > 0:
                digits.insert(0, a)

            return digits

print(Solution.plusOne(Solution(), [9, 9, 9]))
