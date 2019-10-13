/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
	public:
		int rob(vector<int>& a) {
			int n = a.size();

			if (n == 0) return 0;
			if (n == 1) return a[0];

			for (int i = 1; i < n; ++i){
				if (i > 1) a[i] += a[i - 2];
				a[i] = max(a[i], a[i - 1]);
			}

			return a[n - 1];
		}
};
// @lc code=end

