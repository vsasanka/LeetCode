class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        ans = []
        
        nums.sort()
        
        for i in range(0,len(nums)):
            if i>0 and nums[i-1] == nums[i]:
                continue
            
            j = i+1
            k = len(nums) - 1
            
            while j<k:
                '''while j+1<k and nums[j] == nums[j+1]:
                    j = j+1
                while j<k-1 and nums[k] == nums[k-1]:
                    k = k-1'''
                
                if nums[i] + nums[j] + nums[k] == 0:
                    ans.append([nums[i],nums[j],nums[k]])
                    while j<k and nums[j] == nums[j+1]:
                        j += 1
                    while j<k and nums[k] == nums[k-1]:
                        k -= 1
                    j += 1
                    k -= 1
                elif nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                else:
                    j += 1
        
        return ans