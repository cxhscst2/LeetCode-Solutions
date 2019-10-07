#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
	def reverse(self, x: int) -> int:
	fg = ""
	ret = ""
	if x < 0:
	fg = "-"
	x  = -x
	for i in str(x):
		ret = i + ret
		ret = fg +ret
		if int(ret) > pow(2, 31) - 1 or int(ret) < pow(-2, 31):
	return 0
	return int(ret)


# @lc code=end

