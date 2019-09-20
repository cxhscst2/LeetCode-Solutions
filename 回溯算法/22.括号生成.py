class Solution():
    def generateParenthesis(self, n):
        def dfs(l, r, s, ret):
            if l < 0 or r < 0 or l > r:
                return
            if l + r == 0:
                ret.append(s)
                
            dfs(l - 1, r, s + '(', ret)
            dfs(l, r - 1, s + ')', ret)
            
        ret = []
        dfs(n, n, '', ret)
        return ret