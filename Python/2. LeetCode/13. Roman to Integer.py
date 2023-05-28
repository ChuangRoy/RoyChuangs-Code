# https://leetcode.com/problems/roman-to-integer/

"""
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
"""

class Solution:
    def romanToInt(self, s: str) -> int:
        numbers = []
        output = 0
        for i, j in enumerate(s):
            if j == 'I':
                numbers.append(1)
            if j == 'V':
                numbers.append(5)
            if j == 'X':
                numbers.append(10)
            if j == 'L':
                numbers.append(50)
            if j == 'C':
                numbers.append(100)
            if j == 'D':
                numbers.append(500)
            if j == 'M':
                numbers.append(1000)
            if i > 0 and numbers[i - 1] < numbers[i]:
                output += (numbers[i] - numbers[i - 1] - numbers[i - 1])
            else:
                output += numbers[i]
            
        return output
        
sol = Solution()
print(sol.romanToInt("IV"))