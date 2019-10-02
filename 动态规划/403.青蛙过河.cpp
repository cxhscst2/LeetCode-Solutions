/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start

const int N = 2e3 + 10;
class Solution {
	public:
		bool canCross(vector<int> & a) {
			int n = a.size();
			int cnt = 0;

			mp.clear();
			for (auto u : a) mp[u] = cnt++;



			if (a[1] != 1) return false;
			f[1][1] = 1;

			for (int i = 1; i < n - 1; ++i){
				for (int j = f[i]._Find_first(); j != f[i].size();  j = f[i]._Find_next(j)){
					if (mp.count(a[i] + j)){
						int x = mp[a[i] + j];
						f[x][j] = 1;
					}

					if (mp.count(a[i] + j - 1)){
						int x = mp[a[i] + j - 1];
						f[x][j - 1] = 1;
					}

					if (mp.count(a[i] + j + 1)){
						int x = mp[a[i] + j + 1];
						f[x][j + 1] = 1;
					}
				}
			}


			return f[n - 1].count() > 0;
		}

	private:
		bitset <N> f[N];
		unordered_map <int, int> mp;
};
// @lc code=end

