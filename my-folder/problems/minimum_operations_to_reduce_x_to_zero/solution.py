class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total_sum = sum(nums)
        req_sum = total_sum - x

        if req_sum == 0:
            return len(nums)
        
        if req_sum < 0:
            return -1
        
        window_sum = 0
        max_len = -1

        i = 0

        for j in range(len(nums)):
            window_sum += nums[j]
            
            while window_sum > req_sum:
                window_sum -= nums[i]
                i += 1
            
            if window_sum == req_sum:
                max_len = max(max_len, j - i + 1)
        
        if max_len == -1:
            return -1
        return len(nums) - max_len