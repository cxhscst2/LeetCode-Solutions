class Solution:
    def isScramble(self, s: str, t: str) -> bool:
        if s == t:
            return True
        
        if len(s) != len(t):
            return False
        
        n = len(s)
        if sorted(s) != sorted(t):
            return False
        
        if n == 1:
            return True
        
        for i in range(1, n):
            s1 = s[0:i]
            s2 = s[i::]
            
            t1 = t[0:i]
            t2 = t[i::]
            
            if self.isScramble(s[0:i], t[0:i]) and self.isScramble(s[i::], t[i::]):
                return True
            
            if self.isScramble(s[0:i], t[n-i::]) and self.isScramble(s[i::], t[0::n-i]):
                return True
            
            if self.isScramble(s[0:n-i], t[0:n-i]) and self.isScramble(s[n-i::], t[n-i::]):
                return True
            
            if self.isScramble(s[0:n-i], t[i::]) and self.isScramble(s[n-i::], t[0:i]):
                return True
            
        return False
        