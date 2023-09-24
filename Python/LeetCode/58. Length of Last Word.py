# https://leetcode.com/problems/length-of-last-word/

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        word = []
        for i in s[::-1]:
            if i == ' ':
                if word == []:
                    pass
                else:
                    return len(word)
            else:
                word.append(i)
        return len(word)


print(Solution.lengthOfLastWord(Solution(), "Hello World"))
