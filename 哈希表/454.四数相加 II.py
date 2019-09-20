class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        mp1 = collections.defaultdict(int)
        mp2 = collections.defaultdict(int)
        
        for x in A:
            for y in B:
                mp1[x + y] += 1
        
        
        for x in C:
            for y in D:
                mp2[x + y] += 1
                
        ans = 0

        for x, y in mp1.items():
            ans += y * mp2[-x]
            
        return ans