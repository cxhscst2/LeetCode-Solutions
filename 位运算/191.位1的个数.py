class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        ret = 0
        
        while n:
            ret += 1
            n &= n - 1
            
        return ret