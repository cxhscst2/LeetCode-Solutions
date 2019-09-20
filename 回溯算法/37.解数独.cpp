#define rep(i, a, b)    for (int i(a); i <= (b); ++i)
#define dec(i, a, b)    for (int i(a); i >= (b); --i)
#define fi              first
#define se              second


const int A = 10;

class Solution {
	public:


		int f[A][A], r[A][A], c[A][A], v[A][A];
		int ff[A][A];
		bool a[A][A];
		bool rr[A][A], cc[A][A], vv[A][A];

		struct node{
			int x, y;
		} d[90];

		int num, cnt;
		bool flag = false;


		void dfs(int now){
			if (flag) return;
			if (now > num) {
				rep(i, 1, 9) rep(j, 1, 9) ff[i][j] = f[i][j];
				flag = true;
				return;
			}
			int x = d[now].x, y = d[now].y;

			if (flag) return;
			rep(i, 1, 9){
				if (vv[v[x][y]][i]) continue;
				if (cc[c[x][y]][i]) continue;
				if (rr[r[x][y]][i]) continue;
				f[x][y] = i;
				vv[v[x][y]][i] = true;
				cc[c[x][y]][i] = true;
				rr[r[x][y]][i] = true;
				dfs(now + 1);
				f[x][y] = 0;
				vv[v[x][y]][i] = false;
				cc[c[x][y]][i] = false;
				rr[r[x][y]][i] = false;
			}

		}

		void solveSudoku(vector<vector<char>> &a) {

			memset(f, 0, sizeof f);
			memset(cc, false, sizeof cc);
			memset(vv, false, sizeof vv);
			memset(rr, false, sizeof vv);
			memset(d, 0, sizeof d); 

			rep(i, 1, 3) rep(j, 1, 3) v[i][j] = 1;
			rep(i, 1, 3) rep(j, 4, 6) v[i][j] = 2;
			rep(i, 1, 3) rep(j, 7, 9) v[i][j] = 3;
			rep(i, 4, 6) rep(j, 1, 3) v[i][j] = 4;
			rep(i, 4, 6) rep(j, 4, 6) v[i][j] = 5;
			rep(i, 4, 6) rep(j, 7, 9) v[i][j] = 6;
			rep(i, 7, 9) rep(j, 1, 3) v[i][j] = 7;
			rep(i, 7, 9) rep(j, 4, 6) v[i][j] = 8;
			rep(i, 7, 9) rep(j, 7, 9) v[i][j] = 9;
			rep(i, 1, 9) rep(j, 1, 9) r[i][j] = i, c[i][j] = j;
			cnt = 0;
			num = 0;
			for (auto u : a){
				for (auto w : u){
					int x = cnt / 9 + 1;
					int y = cnt % 9 + 1;
					++cnt;

					if (w == '.'){
						f[x][y] = 0;
						d[++num].x = x;
						d[num].y = y;
					}


					else{
						int z = w - 48;
						f[x][y] = z;
						cc[c[x][y]][z] = true;
						vv[v[x][y]][z] = true;
						rr[r[x][y]][z] = true;
					}

				}
			}


			dfs(1);
			rep(i, 1, 9){
				rep(j, 1, 9){
					printf("%d ", ff[i][j]);
					
				}
				putchar(10);
			}


			int et = 0;
			for (auto &u : a){
				for (auto &w : u){
					int x = et / 9 + 1;
					int y = et % 9 + 1;
					++et;

					if (w == '.'){
						w = ff[x][y] + 48;
					}
				}
			}


		}
};

