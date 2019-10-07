#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#

# @lc code=start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        c = [[0] * 205 for i in range(205)]

        c[0][0] = 1
        for i in range(1, 201):
            c[i][0] = c[i][i] = 1
            for j in range(1, i):
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j]
        
        return c[m + n - 2][n - 1]
# @lc code=end

