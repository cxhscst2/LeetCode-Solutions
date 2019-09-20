/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i(a); i <= (b); ++i)
#define dec(i, a, b) for (int i(a); i >= (b); --i)
#define MP make_pair
#define fi first
#define se second

typedef long long LL;


class Solution {
	public:
		int num;
		bool check(int x, int n, int m){
			int ret = 0;
			rep(i, 1, n){
				ret += min(m, x / i);
			}

			return ret >= num;


		}


		int findKthNumber(int m, int n, int k) {
			num = k;
			int l = 1, r = n * m;

			while (l + 1 < r){
				int mid = (l + r) >> 1;
				if (check(mid, n, m)) r = mid;
				else l = mid + 1;
			}

			if (check(l, n, m)) return l;
			else return r;

		}
};

