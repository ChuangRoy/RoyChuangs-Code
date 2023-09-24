#　https://leetcode.com/problems/merge-two-sorted-lists/

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
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        l = []
        l1 = list1
        l2 = list2
        while l1 != None:
            l.append(l1.val)
            l1 = l1.next if l1 else None
        while l2 != None:
            l.append(l2.val)
            l2 = l2.next if l2 else None
        l.sort()
        ret = ListNode(0)
        if l != []:
            ret.val = l[0]
            ret.next = None
            cur = ret
            for i in l[1:]:
                cur.next = ListNode(i)
                cur = cur.next

            return ret
        else:
            ret = ListNode(0)
            ret.val = None
            return
        
        
print(Solution.mergeTwoLists(Solution(), ListNode([1,2,4]), ListNode([1,3,4])))