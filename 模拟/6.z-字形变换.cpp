/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
	public:
		string convert(string s, int m) {
			if (m < 2) return s;
			vector < pair < pair < int, int>, char> > v; 
			int k = m * 2 - 2, l = s.size();
			int p = 0;
			for (int i = 0; i < l; i += k){
				int x = -1, y = i * (m - 1) + 1;
				for (int j = 1; j <= min(k, l - i); ++j){
					if (j <= m) ++x;
					else --x, ++y;
					v.push_back(make_pair(make_pair(x, y), s[p++]));
				}
			}

			sort(v.begin(), v.end());
			string ret = "";
			for (auto u : v) ret = ret + u.second;
			return ret;
		}
};
// @lc code=end

