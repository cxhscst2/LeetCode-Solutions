class Solution:
    def addTwoNumbers(self, l1, l2):
        ret = ListNode(0)
        p = ret
        carry = 0
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            cnt = x + y + carry
            carry = cnt // 10
            p.next = ListNode(cnt % 10)
            p = p.next
            l1 = l1.next if l1 else 0
            l2 = l2.next if l2 else 0
        if carry > 0:
            p.next = ListNode(1)
        return ret.next
