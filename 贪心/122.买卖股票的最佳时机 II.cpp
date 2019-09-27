class Solution {
	public:
		int maxProfit(vector<int>& p) {
			int fg = 0 ;
			int ret = 0;
			int pre = 0;
			for (auto u : p){
				if (fg){
					if (u - pre > 0) ret += (u - pre);
					pre = u;
				}
				else{
					fg = 1;
					pre = u;
				}
			}

			return ret;
		}
};
