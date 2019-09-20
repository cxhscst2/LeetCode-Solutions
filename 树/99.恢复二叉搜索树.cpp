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
		TreeNode* pre;
		TreeNode* s1;
		TreeNode* s2;
		int fg;
		void check(TreeNode* root){
			if (root == NULL) return;
			check(root -> left);   
			if (fg)
			{
				if (pre -> val > root -> val)
				{
					if (s1 == NULL) s1 = pre;
					if (s1 != NULL) s2 = root;
				}
				pre = root;
			}
			else
			{
				fg  = 1;
			}
			pre = root;
			check(root -> right);
		}

		void recoverTree(TreeNode* root){
			fg = 0;
			check(root);
			swap(s1 -> val, s2 -> val);
		}

};
