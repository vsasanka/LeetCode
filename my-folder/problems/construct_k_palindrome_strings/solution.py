from collections import Counter

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        letterfreq = Counter(s)
        
        odds = sum(i & 1 for i in letterfreq.values())
        
        if odds <= k <= len(s):
            return True
        return False