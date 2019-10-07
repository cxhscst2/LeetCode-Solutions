#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])

        c = [[0] * m for i in range(n)]


        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    c[i][j] = 0

                elif i == 0 and j == 0:
                    c[i][j] = 1
                
                elif i == 0:
                    c[i][j] = min(c[i][j - 1], 1)

                elif j == 0:
                    c[i][j] = min(c[i - 1][j], 1)

                else:
                    c[i][j] = c[i - 1][j] + c[i][j - 1]
                

        return c[n - 1][m - 1]
                
                
        
# @lc code=end

