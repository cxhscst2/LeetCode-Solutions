class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        cnt = collections.Counter(frozenset(w) for w in words)
        res = []
        for p in puzzles:
            cur = 0
            for k in range(7):
                for c in itertools.combinations(p[1:], k):
                    cur += cnt[frozenset(tuple(p[0]) + c)]
            res.append(cur)
        return res
