class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			int cnt = 0, now = 0;
			for (auto u : nums){
				if (cnt == 0) now = u, cnt = 1;
				else cnt += (u == now ? 1 : -1);
			}

			return now;
		}
};
