# https://leetcode.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s: str) -> bool:
        another_bracket = [0]
        ret = True
        for i in s:
            if i == "(":
                another_bracket.append(")")
                ret = False
            elif i == "[":
                another_bracket.append("]")
                ret = False
            elif i == "{":
                another_bracket.append("}")
                ret = False
            elif i == another_bracket[-1]:
                another_bracket.pop(-1)
                ret = False
                if len(another_bracket) == 1:
                    ret = True
            elif i == ")" or i == "]" or i == "}":
                return False
            else:
                ret = False


        return ret

sol = Solution()
print(sol.isValid("([)]"))