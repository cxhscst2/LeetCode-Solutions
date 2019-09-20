# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:    
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        
        ret = ListNode(0)
        ret.next = head
        r1 = ret
        
        now = 0
        while head:
            now += 1
            if now < m:
                r1 = head
                head = head.next
                
            elif now == m:
                p = plast = head
                head = head.next
                p.next = None
                
            
            elif now > m and now <= n:
                tmp = head
                head = head.next
                tmp.next = p
                p = tmp
                r1.next = p
                 
            else:
                plast.next = head
                break
        
        
        return ret.next
                
        
                
                