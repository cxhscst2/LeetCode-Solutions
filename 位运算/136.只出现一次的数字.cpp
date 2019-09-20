class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int ret = 0;
			for (auto u : nums) ret ^= u;
			return ret;

		}
};
