# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast = head
        slow = head
        
        for i in range(n):
            fast = fast.next
            
        if not fast:
            return head.next
            
        while fast.next:
            fast = fast.next
            slow = slow.next
        
        now = slow.next
        slow.next = slow.next.next
        now.next = None
       
        return head
        
        