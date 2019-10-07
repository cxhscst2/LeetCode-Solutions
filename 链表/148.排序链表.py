#
# @lc app=leetcode.cn id=148 lang=python
#
# [148] 排序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def mergeTwoLists(self, l1, l2):
		l3 = ListNode(0)
		ret = l3

		while l1 and l2:
		if (l1.val < l2.val):
			l3.next = l1
			l1 = l1.next
			else:
			l3.next = l2
			l2 = l2.next
			l3 = l3.next

			if l1:
			l3.next = l1
			elif l2:
			l3.next = l2

			return ret.next

			def get_mid(self, head):
				if not head:
				return None
				fast = slow = head
				while fast.next and fast.next.next:
				slow = slow.next
				fast = fast.next.next
				return slow


				def sortList(self, head):
					"""
						:type head: ListNode
						 :rtype: ListNode
						 """

						 if head is None or head.next is None:
	return head
mid = self.get_mid(head)
	l = head
	r = mid.next
	mid.next = None
return self.mergeTwoLists(self.sortList(l), self.sortList(r))


# @lc code=end

