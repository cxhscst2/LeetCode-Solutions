/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 *
 * https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (35.11%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    1.1K
 * Total Submissions: 3.1K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n[[],[1],[1],[2],[],[1],[]]'
 *
 * 设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
 * 
 * 注意: 允许出现重复元素。
 * 
 * 
 * insert(val)：向集合中插入元素 val。
 * remove(val)：当 val 存在时，从集合中移除一个 val。
 * getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
 * 
 * 
 * 示例:
 * 
 * // 初始化一个空的集合。
 * RandomizedCollection collection = new RandomizedCollection();
 * 
 * // 向集合中插入 1 。返回 true 表示集合不包含 1 。
 * collection.insert(1);
 * 
 * // 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
 * collection.insert(1);
 * 
 * // 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
 * collection.insert(2);
 * 
 * // getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
 * collection.getRandom();
 * 
 * // 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
 * collection.remove(1);
 * 
 * // getRandom 应有相同概率返回 1 和 2 。
 * collection.getRandom();
 * 
 * 
 */
class RandomizedCollection {
	public:
		/** Initialize your data structure here. */
		RandomizedCollection() {
			srand(time(NULL));
		}

		/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
		bool insert(int val){
			bool ret = s[val].empty();
			s[val].insert(a.size());
			a.push_back(val);
			return ret;
		}

		/** Removes a value from the collection. Returns true if the collection contained the specified element. */
		bool remove(int val){
			if (s[val].empty()) return false;
			int id = *s[val].begin();
			s[val].erase(id);

			if (id + 1 != a.size()){
				int tmp = a.back();
				a[id] = tmp;
				s[tmp].erase(a.size() - 1);
				s[tmp].insert(id);
			}

			a.pop_back();
			return true;
		}

		/** Get a random element from the collection. */
		int getRandom() {
			if (a.size() == 0) return NULL;
			return a[rand() % a.size()];
		}

	private:
		vector <int> a;
		unordered_map <int, unordered_set <int> > s;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

