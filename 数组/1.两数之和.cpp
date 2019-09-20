/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
	public:
		vector <int> twoSum(vector<int>& nums, int target) {
			unordered_map < int, vector <int>  > mp;

			int i = 0;
			for (auto u : nums){
				mp[u].push_back(i++);
			}


			i = 0;

			vector <int> ret;

			for (auto u : nums){
				int cnt = target - u;
				if (mp.count(cnt)){
					for (auto w : mp[cnt]){
						if (i ^ w){
							ret.push_back(i);
							ret.push_back(w);
							return ret;
						}

					}

				}

				++i;

			}

			return ret;



		}
};

