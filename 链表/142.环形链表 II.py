# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
 
class Solution(object):
    def detectCycle(self, head):
        if not head or not head.next:
            return None
        
        slow, fast = head, head
        while fast:
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
                
            if slow == fast:
                break
                
                
        if slow != fast:
            return None
        
        fast = head
        while True:
            if slow == fast:
                return slow
            slow = slow.next
            fast = fast.next
