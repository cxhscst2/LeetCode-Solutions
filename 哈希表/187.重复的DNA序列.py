class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        mp = collections.defaultdict(int)
        for i in range(len(s) - 9):
            mp[s[i:i+10]] += 1
            
        return [x for x, y in mp.items() if y > 1]