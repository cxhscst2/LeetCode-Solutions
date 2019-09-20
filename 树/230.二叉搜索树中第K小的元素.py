# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    tot = 0
    ans = 0
    flag = False
    m = 0
    
    def dfs(self, cnt : TreeNode):
        if self.flag:
            return
        
        if not cnt:
            return
        
        self.dfs(cnt.left)
        print(cnt.val)
        self.tot += 1
        if self.tot == self.m:
            self.ans = cnt.val
            flag = True
            return
    
        self.dfs(cnt.right)
            
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.m = k
        self.dfs(root)
        return self.ans
        
        