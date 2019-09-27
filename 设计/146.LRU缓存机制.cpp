#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		        make_pair
#define fi		        first
#define se		        second

class LRUCache {
	private:
		int up;
		int cnt;
		list< pair<int, int>> queue;		
		unordered_map< int, list<pair<int, int>>::iterator> mp;

	public:
		LRUCache(int capacity){
			up = capacity;
			mp.clear();
			cnt = 0;

		}

		int get(int key){
			int ret = -1;
			auto p = mp.find(key);
			if (p != mp.end()){
				ret = p -> se -> se;
				queue.erase(p -> se);
				queue.push_front(MP(key, ret));
				p -> se = queue.begin();
			}

			return ret;

		}

		void put(int key, int value){
			auto p = mp.find(key);
			if (p != mp.end()){
				queue.erase(p -> se);
			}

			else if (cnt == up){
				int delkey = queue.back().fi;
				queue.pop_back();
				mp.erase(delkey);
			}

2			else ++cnt;

			queue.push_front(MP(key, value));
			mp[key] = queue.begin();
		}
};



