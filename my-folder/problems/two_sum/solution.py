class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        
        for i in range(0,len(nums)):
            complement = target - nums[i]
            if complement in dic:
                return [dic[complement],i]
            dic[nums[i]] = i
            
        return [0,1]