class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        total = 0
        l, r = 0, 0
        vowels = ['a', 'e', 'i', 'o', 'u']
        res = 0

        for r in range(len(s)):
            if s[r] in vowels:
                total += 1

            res = max(res, total)

            if r - l + 1 < k:
                continue

            if s[l] in vowels:
                total -= 1
            l += 1
            
        
        return res