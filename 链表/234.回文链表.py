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
    
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        
        slow = fast = last = head
        
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            
        fast = slow.next
        slow.next = None
        
        fast = self.reverseList(fast)

        while fast and head:
            if fast.val != head.val:
                return False
            fast = fast.next
            head = head.next


        return True
        