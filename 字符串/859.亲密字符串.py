#
# @lc app=leetcode.cn id=859 lang=python3
#
# [859] 亲密字符串
#
# https://leetcode-cn.com/problems/buddy-strings/description/
#
# algorithms
# Easy (26.85%)
# Likes:    57
# Dislikes: 0
# Total Accepted:    6.1K
# Total Submissions: 22.7K
# Testcase Example:  '"ab"\n"ba"'
#
# 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false
# 。
# 
# 
# 
# 示例 1：
# 
# 输入： A = "ab", B = "ba"
# 输出： true
# 
# 
# 示例 2：
# 
# 输入： A = "ab", B = "ab"
# 输出： false
# 
# 
# 示例 3:
# 
# 输入： A = "aa", B = "aa"
# 输出： true
# 
# 
# 示例 4：
# 
# 输入： A = "aaaaaaabc", B = "aaaaaaacb"
# 输出： true
# 
# 
# 示例 5：
# 
# 输入： A = "", B = "aa"
# 输出： false
# 
# 
# 
# 
# 提示：
# 
# 
# 0 <= A.length <= 20000
# 0 <= B.length <= 20000
# A 和 B 仅由小写字母构成。
# 
# 
#
class Solution:
    def buddyStrings(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        if s == t and len(s) != len(set(s)):
            return True

        dif = [(a, b) for a, b in zip(s, t) if a != b]
        return len(dif) == 2 and dif[0] == dif[1][::-1]   


