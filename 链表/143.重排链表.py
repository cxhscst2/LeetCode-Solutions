# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        ret = None
        while head:
            nxt = head.next
            head.next = ret
            ret = head
            head = nxt
        
        return ret
    
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return;
        
        now = ret = ListNode(0)
        
        slow = fast = last = head
        
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            
        fast = slow.next
        slow.next = None
        
        fast = self.reverseList(fast)
        
        while head and fast:
            tmp = head
            head = head.next
            now.next = tmp
            tmp.next = None
            now = now.next
            
            tmp = fast
            fast = fast.next
            now.next = tmp
            tmp.next = None
            now = now.next

        if head:
            now.next = head
        
        head = ret.next