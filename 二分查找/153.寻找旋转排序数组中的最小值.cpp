/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (49.54%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 35.6K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 * 
 */
class Solution {
	public:
		int findMin(vector<int>& a) {
			int n = a.size();
			int l = 0, r = n - 1;

			while (l + 1 < r){
				int mid = (l + r) >> 1;

				if (a[mid] > a[r]) l = mid;
				else r = mid;
			}


			if (a[l] < a[r]) return a[l];
			else return a[r];

		}
};

