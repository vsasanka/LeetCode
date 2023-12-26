class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        freq = collections.defaultdict(int)

        l, res, total = 0, 0, 0

        for r in range(len(fruits)):
            freq[fruits[r]] += 1
            total += 1

            while len(freq) > 2:
                f = fruits[l]
                freq[f] -= 1
                total -= 1
                l += 1

                if freq[f] == 0:
                    freq.pop(f)
            
            res = max(res, r - l + 1)

        return res