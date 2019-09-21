/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
	public:
		int calc(vector <int> &a, vector <int> &b, int k){
			int x = 0, y = 0;
			int n = a.size(), m = b.size();
			while (x + y < k){
				if (x == n){
					y = k - n;
					break;
				}

				if (y == m){
					x = k - m;
					break;
				}

				int z = (k - x - y + 1) >> 1;

				int nx = min(x + z, n);
				int ny = min(y + z, m);

				int vx = a[nx - 1];
				int vy = b[ny - 1];

				if (vx < vy) x = nx;
				else y = ny;

				printf("%d %d\n", x, y);

			}

			if (!x) return b[y - 1];
			else if (!y) return a[x - 1];
			else return max(a[x - 1], b[y - 1]);
		}


		double findMedianSortedArrays(vector <int> & a, vector< int> & b) {
			int n = a.size(), m = b.size();
			int all = n + m;
			if (all & 1) return (double)calc(a, b, (all + 1) >> 1);
			else return (calc(a, b, all >> 1) + calc(a, b, (all >> 1) + 1)) / 2.0;

		}
};
