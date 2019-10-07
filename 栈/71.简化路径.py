#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        path.replace('//', '/')
        list = path.split('/')
        ret = []
        for i in range(len(list)):
            if list[i] == '..' and len(ret) > 0:
                ret.pop()
            elif list[i] != '' and list[i] != '.' and list[i] != '..':
                ret.append(list[i])
        return '/'+'/'.join(ret)

# @lc code=end

