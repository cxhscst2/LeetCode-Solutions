#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second

typedef long long LL;

const int N = 32;
const int M = 3e5 + 10;




class Solution {
	public:

		int a[N];
		int cnt;
		int n = 0, s = 0;
		bitset <M> f[N];
		bool splitArraySameAverage(vector<int>& b){
			for (auto u : b) s += u, ++n;
			int g = __gcd(s, n);

			s /= g, n /= g;

			cnt = 0;
			f[0][0] = 1;
			for (auto u : b){
				++cnt;
				dec(j, cnt, 1) f[j] |= (f[j - 1] << u);
			}

			cnt = 0;

			for (auto u : b){
				++cnt;
				if (cnt == (int)b.size()) break;
				if (cnt * s % n == 0){
					int x = cnt, y = x * s / n;
					if (f[x][y]) return true;
				}
			}

			return false;
		}
};
