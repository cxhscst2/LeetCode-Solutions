# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    mx = -10 ** 18
    
    def calc(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        l = self.calc(root.left)
        r = self.calc(root.right)
        
        now = root.val
        if l > 0:
            now += l
        if r > 0:
            now += r
            
        self.mx = max(self.mx, now)
        
        return max(root.val, root.val + l, root.val + r)
        
    def maxPathSum(self, root: TreeNode) -> int:
        mx = 0
        self.calc(root)
        return self.mx

        