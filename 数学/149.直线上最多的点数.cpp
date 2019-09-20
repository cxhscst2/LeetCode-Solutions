#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second

const int N = 1e5 + 10;
const long double eps = 1e-18;


class Solution {
	public:

		long double a[N], b[N], f[N];
		int n = 0;
		int maxPoints(vector<Point>& aa) {
			for (auto u : aa) a[++n] = u.x, b[n] = u.y;

			if (n <= 1) return n;

			int mx = 1;


			rep(i, 1 ,n){
				int cnt = 0;
				int yy  = 1;


				rep(j, 1, n) if (i ^ j){
					if (fabs(a[i] - a[j]) < eps && fabs(b[i] - b[j]) < eps) ++yy;
					else if (fabs(a[i] - a[j]) < eps) f[++cnt] = 2e9;
					else f[++cnt] = (b[j] - b[i]) / (a[j] - a[i]); 
				}

				if (cnt == 0) return n;

				sort(f + 1, f + cnt + 1);

				f[0] = -2e9;

				int now = 1;
				rep(j, 2, cnt){
					if (fabs(f[j] - f[j - 1]) < eps){
						++now;

					}

					else{
						mx = max(mx, now + yy);
						now = 1; 
					}
				}

				mx = max(mx, now + yy);
			}

			return mx;

		}
};
