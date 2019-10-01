#
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#

# @lc code=start
class Solution:
    def minDistance(self, a: str, b: str) -> int:
            n = len(a)
            m = len(b)

            f = [[0] * (m + 10) for i in range(n + 10)]


            for i in range(1, n + 1):
                f[i][0] = i


            for i in range(1, m + 1):
                f[0][i] = i

            for i in range(1, n + 1):
                for j in range(1, m + 1):
                    if a[i - 1] == b[j - 1]:
                        now = 0
                    else:
                        now = 1
                    
                    f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + now)
            

            return f[n][m]
        
# @lc code=end

