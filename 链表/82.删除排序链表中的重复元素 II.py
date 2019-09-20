# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        now = ret = ListNode(0)
        
        while head:
            if head.next and head.val == head.next.val:
                while head.next and head.val == head.next.val:
                    head = head.next
                
                head = head.next
                
            if not head:
                break
                
            if head.next and head.val == head.next.val:
                continue

            pre = head
            head = head.next
            pre.next = None
            now.next = pre
            now = now.next
            
        return ret.next
                