class Solution {
	public:
		string S1, S2;
		int l1, l2;
		int f[2010][2010];

		bool judge(int x, int y){
			if (~f[x][y]) return f[x][y];
			if (x == l1 && y == l2) return f[x][y] = 1;
			if (y == l2) return f[x][y] = 0;
			if (x == l1){
				for (register int i = y; i < l2; ++i) if (S2[i] != '*') return f[x][y] = 0;
				return f[x][y] = 1;
			}


			if (S2[y] == '?'){
				if (judge(x + 1, y + 1)) return f[x][y] = 1;
				return f[x][y] = 0;
			}

			else if (S2[y] == '*'){
				for (register int i = x; i <= l1; ++i) if (judge(i, y + 1)) return f[x][y] = 1;
				return f[x][y] = 0;
			}

			if (S1[x] != S2[y]) return f[x][y] = 0;
			return judge(x + 1, y + 1);
		}

		bool isMatch(string s1, string s2){
			S1 = s1, S2 = s2;
			l1 = s1.size();
			l2 = s2.size();

			for (int i = 0; i <= l1 + 2; ++i) for (int j = 0; j <= l2 + 2; ++j) f[i][j] = -1;

			return judge(0, 0);
		}

};