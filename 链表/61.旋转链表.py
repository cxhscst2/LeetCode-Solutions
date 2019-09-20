# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        
        if not head:
            return None
        
        l = 1
        now = head
        while now.next:
            l += 1
            now = now.next
            
        k %= l
        
        now.next = head
        
        for i in range(l - k):
            now = now.next
        
        ret = now.next
        now.next = None
        
        return ret
        