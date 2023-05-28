# https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
class ListNode():
    def __init__(self, val):
        if isinstance(val,int):
            self.val = val
            self.next = None
            
        elif isinstance(val,list):
            self.val = val[0]
            self.next = None
            cur = self
            for i in val[1:]:
                cur.next = ListNode(i)
                cur = cur.next
    
    def gatherAttrs(self):
        return ", ".join("{}: {}".format(k, getattr(self, k)) for k in self.__dict__.keys())

    def __str__(self):
            return self.__class__.__name__+" {"+"{}".format(self.gatherAttrs())+"}"


from typing import Optional, Callable, Any, Tuple

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        output = ListNode((l1.val + l2.val + carry) % 10)
        carry = (l1.val + l2.val + carry) // 10
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
        output2 = output
        while l1 != None or l2 != None or carry != 0:
            if l1 is None:
                l1Val = 0
            else:
                l1Val = l1.val
            if l2 is None:
                l2Val = 0
            else:
                l2Val = l2.val
            output2.next = ListNode((l1Val + l2Val + carry) % 10)
            output2 = output2.next if output2 else None
            carry = (l1Val + l2Val + carry) // 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        return output
        
sol = Solution()

print(sol.addTwoNumbers(ListNode([2,4,3]), ListNode([5,6,4])))