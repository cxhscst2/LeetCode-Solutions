/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
	public:
		bool isValidBST(TreeNode* root) {
			vector <int> v;
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
					v.push_back(cnt -> val);
					cnt = cnt -> right;
				}
			}


			int fg = 0, now = 0;
			for (auto u : v){
				if (fg){
					if (u <= now) return false;
				}
				else{
					fg = 1;
				}
				now = u;
			}

			return true;
		}
};
