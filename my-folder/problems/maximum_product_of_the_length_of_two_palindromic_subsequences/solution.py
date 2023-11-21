class Solution:
    def maxProduct(self, s: str) -> int:
        
        N = len(s)
        res = {}

        for mask in range(1, 1 << N):
            subseq = ""

            for i in range(N):
                if mask & (1 << i):
                    subseq += s[i]
            
            if subseq == subseq[::-1] and len(subseq) > 0:
                
                res[mask] = len(subseq)

        ans = 0
        
        for m1 in res:
            for m2 in res:
                if (m1 & m2) == 0:
                    ans = max(ans, res[m1]*res[m2])
        
        return ans
