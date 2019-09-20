class Solution:
    def findErrorNums(self, a: List[int]) -> List[int]:
        n = len(a)
            
        for i in range(n):
            while (a[i] != a[a[i] - 1]):
                x = i;
                y = a[i] - 1
                a[x], a[y] = a[y], a[x]

        for i in range(n):
            if (a[i] != i + 1):
                return a[i], i + 1;