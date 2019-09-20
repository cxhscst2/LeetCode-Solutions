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
		bool isSameTree(TreeNode* p, TreeNode* q) {
			if (p == NULL) return q == NULL;
			if (q == NULL) return p == NULL;
			bool ret = true;
			ret &= (p -> val == q -> val);

			int pl = (p -> left  != NULL);
			int pr = (p -> right != NULL);
			int ql = (q -> left  != NULL);
			int qr = (q -> right != NULL);

			if (pl ^ ql) return false;
			if (pr ^ qr) return false;

			if (pl)  ret &= isSameTree(p -> left , q -> left);
			if (pr)  ret &= isSameTree(p -> right, q -> right);
			return ret;
		}
};
