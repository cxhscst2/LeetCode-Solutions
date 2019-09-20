#
# @lc app=leetcode.cn id=349 lang=python3
#
# [349] 两个数组的交集
#
class Solution:
    def intersection(self, a: List[int], b: List[int]) -> List[int]:
        a = set(a)
        b = set(b)
        return [x for x in a if x in b]

