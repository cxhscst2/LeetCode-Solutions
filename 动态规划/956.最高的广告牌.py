class Solution:
    def tallestBillboard(self, a: List[int]) -> int:
        f = {0:0}
        
        for x in a:
            c = f.copy()
            for y, val in c.items():
                f[x + y] = max(f.get(x + y, 0), val)
                f[abs(x - y)] = max(f.get(abs(x - y), 0), val + min(x, y))

                
        return f[0]
        