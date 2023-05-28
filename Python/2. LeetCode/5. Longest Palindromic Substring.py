# https://leetcode.com/problems/longest-palindromic-substring/

class Solution:  # Sloution By: https://medium.com/hoskiss-stand/manacher-299cf75db97e
    def longestPalindrome(self, s: str) -> str:
        string_size = len(s)
        if string_size < 3:
            if s==s[::-1]:
                return s
            else:
                return s[0]

        manacher_str = "#"
        for index in range(len(s)):
            manacher_str += s[index]
            manacher_str += "#"

        LPS_table = [0]*len(manacher_str)
        center = 1
        max_right = 2
        max_length = 0
        LPS_center = 0

        total_size = len(manacher_str)
        for index in range(1, len(manacher_str)):
            if index < max_right:
                LPS_table[index] = min(LPS_table[2*center-index], max_right-index)
            else:
                LPS_table[index] = 0

            # when calculating LPS value, self position (index) is not included
            while (index-LPS_table[index]-1 >= 0 and
                   index+LPS_table[index]+1 < total_size and
                   manacher_str[index-LPS_table[index]-1] == manacher_str[index+LPS_table[index]+1]):
                   LPS_table[index] += 1

            if LPS_table[index] > max_length:
                max_length = LPS_table[index]
                LPS_center = index

            if LPS_table[index]+index-1 > max_right:
                max_right = LPS_table[index]+index-1
                center = index

        start = int((LPS_center-max_length)/2)
        return s[start: start+max_length]

sol = Solution()
print(sol.longestPalindrome("babad"))