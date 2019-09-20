class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector <int> ret;
			stack <TreeNode*> s;
			TreeNode *cnt = root;
			while (cnt || !s.empty()){
				while (cnt){
					s.push(cnt);
					cnt = cnt -> left;
				}

				if (!s.empty()){
					cnt = s.top();
					s.pop();
					ret.push_back(cnt -> val);
					cnt = cnt -> right;
				}
			}

			return ret;
		}
};
