/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
class Solution {
	public:
		bool isHappy(int n) {
			for (unordered_map <int, int> mp; n ^ 1; ){
				int s = 0;
				for (; n; n /= 10) s += (n % 10) * (n % 10);
				n = s;
				if (mp.count(n)) return false;
				mp[n] = 1;
			}

			return true;
		}
};

