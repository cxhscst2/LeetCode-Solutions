/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */
class Solution {
	public:
		int addDigits(int x){
			if (!x) return 0;
			if (x % 9 == 0) return 9;
			return x % 9;
		}
};

