class Solution:
    def grayCode(self, n: int) -> 'List[int]':
        if not n:
            return [0]
        
        a = [0, 1]
        for i in range(1, n):
            b = a
            c = [(1 << i) ^ j for j in a[::-1]]
            a = b + c
        return a
