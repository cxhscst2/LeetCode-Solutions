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


    def mergeKLists(self, l):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        n = len(l)
        
        if not n:
            return None
        
        if n == 1:
            return l[0]
        
        mid = n >> 1

        l1 = self.mergeKLists(l[0:mid])
        l2 = self.mergeKLists(l[mid:n])

        return self.mergeTwoLists(l1, l2)

        


