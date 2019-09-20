class Solution(object):
    def findDuplicate(self, nums):
        x = y = 0
        while True:
            x = nums[x]
            y = nums[nums[y]]
            if x == y:
                break
        y = 0
        while x != y:
            x = nums[x]
            y = nums[y]
        return x