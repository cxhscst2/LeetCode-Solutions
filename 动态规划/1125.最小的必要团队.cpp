#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1 << 16 | 100;

class Solution {
	public:
		int c[N], f[N], g[N], h[N];

		void print(LL x){
			for (int i = 0; i < 60; ++i)  if (x >> i & 1) putchar(49); else putchar(48); putchar(10);
		}

		int calc(LL x){
			int ret = 0;
			for (; x; x >>= 1) ret += (x & 1);
			return ret;
		}

		vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& a){
			memset(c, 0, sizeof c);
			memset(g, 0, sizeof g);
			memset(h, 0, sizeof h);

			memset(f, 0x3f, sizeof f);

			map <string, int> mp;
			int m = (int)req.size();
			int n = (int)a.size();
			int cnt = 0;
			for (auto u : req){
				mp[u] = cnt++;
			}

			int all = (1 << m) - 1;

			f[0] = 0;
			g[0] = -1;
			h[0] = -1;

			cnt = -1;
			for (auto people : a){
				++cnt;
				int now = 0;
				for (auto u : people){
					now ^= (1 << mp[u]);
				}

				c[cnt] = now;
			}

			for (int i = 0; i < n; ++i){
				for (int j = all; ~j; --j){
					if (f[j | c[i]] > f[j] + 1){
						f[j | c[i]] = f[j] + 1;
						g[j | c[i]] = i;
						h[j | c[i]] = j;
					}
				}
			}

			vector <int> ret;

			for (int j = all; j; j = h[j]) ret.push_back(g[j]);

			return ret;
		}
};



