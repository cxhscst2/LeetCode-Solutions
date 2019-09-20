# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        s = set()
        now = ret = ListNode(0)
        
        while head:
            if not head.val in s:
                s.add(head.val)
                now.next = head
                now = now.next
            
            head = head.next
            
        now.next = None
        return ret.next