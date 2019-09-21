/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (45.08%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 16.3K
 * Testcase Example:  '[1,3,5]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 注意数组中可能存在重复的元素。
 * 
 * 示例 1：
 * 
 * 输入: [1,3,5]
 * 输出: 1
 * 
 * 示例 2：
 * 
 * 输入: [2,2,2,0,1]
 * 输出: 0
 * 
 * 说明：
 * 
 * 
 * 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 * 
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
				else if (a[mid] < a[r]) r = mid;
				else --r;
			}


			if (a[l] < a[r]) return a[l];
			else return a[r];

		}
};

