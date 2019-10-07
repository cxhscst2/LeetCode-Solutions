#
# @lc app=leetcode.cn id=456 lang=python3
#
# [456] 132模式
#

# @lc code=start
class Solution:
    def find132pattern(self, a: List[int]) -> bool:
        a = a[::-1]
        a3 = -100000000000000000

        s = []

        for x in a:
            if x < a3:
                return True
            while (s and x > s[-1]):
                a3 = s[-1]
                s.pop()
            s.append(x)

        return False



    
        
# @lc code=end

