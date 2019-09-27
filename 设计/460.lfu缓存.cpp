/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (33.41%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 4K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
 * 
 * get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
 * put(key, value) -
 * 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
 * 
 * 进阶：
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 * 
 * 示例：
 * 
 * 
 */

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		        make_pair
#define fi		        first
#define se		        second

class LFUCache {
	private:
		int up;
		int mn;
		int cnt;
		unordered_map < int, pair <int, int>  >  m;
		unordered_map < int, list <int> > q;
		unordered_map < int, list <int> ::iterator > mp;

	public:
		LFUCache(int capacity) {
			up = capacity;
			mn = 0;
			cnt = 0;

		}

		int get(int key) {
			if (!m.count(key)) return -1;
			q[m[key].se].erase(mp[key]);
			++m[key].se;
			q[m[key].se].push_front(key);
			mp[key] = q[m[key].se].begin();

			if (q[mn].size() == 0) ++mn;
			return m[key].fi;

		}

		void put(int key, int value) {
			if (up <= 0) return;
			if (get(key) != -1){
				m[key].fi = value;
				return;
			}

			if (m.size() >= up){
				m.erase(q[mn].back());
				mp.erase(q[mn].back());
				q[mn].pop_back();
			}

			m[key] = {value, 1};
			q[1].push_front(key);
			mp[key] = q[1].begin();
			mn = 1;
		}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

