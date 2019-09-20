#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef unsigned long long LL;

const int N = 1e3 + 10;
const LL base = 20123;

class Solution {
	public:
		int n, m;
		int a[N];
		int f[N];
		LL  Hash[N], bin[N];

		void init(){
			bin[0] = 1; rep(i, 1, n) bin[i] = bin[i - 1] * base;
			rep(i, 1, n) Hash[i] = Hash[i - 1] * base + (a[i] + 100);
		}

		inline LL gethash(int l, int r){ return Hash[r] - Hash[l - 1] * bin[r - l + 1]; }

		int calc(int x){
			if (~f[x]) return f[x];
			
			if (x > m){
				return f[x] = (n & 1);
			}


			int ret = 1;
			rep(i, x, m){
                int len = i - x + 1;
				if (gethash(x, i) == gethash(n - x + 2 - len, n - x + 1)){
					ret = max(ret, 2 + calc(i + 1));
				}
			}

			return f[x] = ret;
		}


		int longestDecomposition(string text){
			memset(f, -1, sizeof f);

			for (auto u : text){
				a[++n] = u - 'a' + 1;
			}
			
			m = n >> 1;

			init();

			return calc(1);

		}
};



