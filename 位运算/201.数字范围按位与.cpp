#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

class Solution {
	public:
		int rangeBitwiseAnd(int m, int n){
			long long len = 0ll + n - m + 1;
			int ret = 0;
			rep(i, 0, 30){
				int now = 1 << i;
				if (len > now) continue;
				if ((m >> i & 1) && (n >> i & 1)) ret ^= (1 << i);
			}

			return ret;

		}
};