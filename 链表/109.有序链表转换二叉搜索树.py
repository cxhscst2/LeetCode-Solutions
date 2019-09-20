# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if not head:
            return None
        
        slow = fast = last = head
        
        while fast.next and fast.next.next:
            last = slow
            slow = slow.next
            fast = fast.next.next
            
        fast = slow.next
        last.next = None
        
        ret = TreeNode(slow.val)
        if head != slow:
            ret.left = self.sortedListToBST(head)
            
        ret.right = self.sortedListToBST(fast)
        
        return ret
        