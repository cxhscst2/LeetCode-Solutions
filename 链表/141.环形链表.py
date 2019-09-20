class Solution(object):
    def hasCycle(self, head):
        if not head or not head.next:
            return False
        
        slow, fast = head, head
        while fast:
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
                
            if slow == fast:
                break
                
        if slow != fast:
            return False
        
        return True