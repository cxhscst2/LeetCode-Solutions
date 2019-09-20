#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

class MinStack {
	private:
		stack <int> s, t;
	public:
		/** initialize your data structure here. */
		MinStack(){

		}

		void push(int x){
			s.push(x);
			if (t.empty() || x <= t.top()){
				t.push(x);
			}

		}

		void pop(){
			int now = s.top();
			s.pop();
			if (!t.empty() && t.top() == now){
				t.pop();
			}

		}

		int top(){
			return s.top();

		}

		int getMin(){
			return t.top();

		}
};




