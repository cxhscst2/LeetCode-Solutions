# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        a = headA
        b = headB
        if not a or not b:
            return None
        
        while (a != b):
            if (not a):
                a = headB
            else:
                a = a.next
            
            if (not b):
                b = headA
            else:
                b = b.next
            
        
        
        return a
        
        