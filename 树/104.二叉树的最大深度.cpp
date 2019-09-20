/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *l;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), l(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		int mx;

		void dfs(TreeNode* root, int dep){
			if (!root) return;
			mx = max(mx, dep);
			dfs(root -> l, dep + 1);
			dfs(root -> right, dep + 1);

		}
		int maxDepth(TreeNode* root) {
			mx = 0;
			dfs(root, 1);
			return mx;

		}
};

