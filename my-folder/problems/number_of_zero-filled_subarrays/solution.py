class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        total_count = 0

        count = 0

        for i in nums:
            if i == 0:
                count += 1
            else:
                total_count += count*(count+1)//2
                count = 0

        total_count += count*(count + 1) // 2

        return total_count