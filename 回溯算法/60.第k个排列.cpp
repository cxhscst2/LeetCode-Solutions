#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second

typedef long long LL;

class Solution {
	public:
		int a[20], c[20];
		int tot = 0;
		int K;
		string st;
		void check(int n){
			++tot;
			if (tot ^ K) return;
			rep(i, 1, n) st += (char)(a[i] + 48);
		}

		void dfs(int x, int n){
			if (x > n){
				check(n);
				return;
			}

			rep(i, 1, n) if (!c[i]){
				a[x] = i;
				c[i] = 1;
				dfs(x + 1, n);
				c[i] = 0;
			}
		}
		string getPermutation(int n, int k){
			K = k;
            		memset(c, 0, sizeof c);
			dfs(1, n);
			return st;
		}
};
