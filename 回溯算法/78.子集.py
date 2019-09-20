class Solution(object):
    def subsets(self, a):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        n = len(a)
        return [[a[j] for j in range(n) if i >> j & 1] for i in range(2 ** n)]
        