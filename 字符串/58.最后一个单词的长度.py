#
# @lc app=leetcode.cn id=58 lang=python3
#
# [58] ���һ�����ʵĳ���
#
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        if not a:
            return 0
        return len(a[-1])
        

