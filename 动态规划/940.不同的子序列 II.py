class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10 ** 9 + 7
        e = [0] * 26
        for u in s:
            e[ord(u) - 97] = (sum(e) + 1) % mod
            
        return sum(e) % mod
            
        