class Solution {
public:
    int f[1 << 16 | 10];
    int countTriplets(vector<int>& a) {
        int n = (int)a.size();
        int all = 1 << 16;
        memset(f, 0, sizeof f);

        for (auto u : a) ++f[u];

        for (int i = 0; i < 16; ++i){
            for (int j = 0; j < all; ++j){
                if ((j >> i) & 1) f[j] += f[j ^ (1 << i)];
            }
        }


        int ans = 0;
        for (auto u : a){
            for (auto w : a){
                ans += f[(all - 1) ^ (u & w)];
            }
        }


        return ans;
        
    }
};
