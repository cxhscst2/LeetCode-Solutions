#
# @lc app=leetcode.cn id=115 lang=python3
#
# [115] 不同的子序列
#

# @lc code=start
class Solution:
    def numDistinct(self, s: str, t: str):
        m, n = len(s) + 1, len(t) + 1
        f = [[1] * m for _ in range(n)]
        for i in range(1, n):
            f[i][0] = 0
 
        for i in range(1, n):
            for j in range(1, m):
                f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * (t[i - 1] == s[j - 1])
        return f[-1][-1]

        
# @lc code=end

