# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        ans = 0
        now = 0
        s   = dict(zip(G, [1] * len(G)))
        while head:
            if head.val in s:
                now = 1
            elif now > 0:
                now = 0
                ans += 1
    
            head = head.next
        
        if now > 0:
            ans += 1
        return ans
        