# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        ret = None
        while head:
            nxt = head.next
            head.next = ret
            ret = head
            head = nxt
        
        return ret
        