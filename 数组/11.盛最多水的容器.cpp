class Solution {
	public:
		int maxArea(vector<int>& a){
			vector <int> v[20100];
			int up = 0;
			int mx = 0, mn = 2e9;
			int ans = 0;

			int pos = 0;
			for (auto u : a) v[u].push_back(++pos), up = max(up, u);

			for (int i = up; i; --i){
				if (v[i].size() > 0){
					for (auto u : v[i]){
						mx = max(mx, u);
						mn = min(mn, u);
					}
					ans = max(ans, (mx - mn) * i);
				}
			}

			return ans;

		}
};
