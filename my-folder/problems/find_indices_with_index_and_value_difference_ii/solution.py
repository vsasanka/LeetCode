class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        ans = [-1,-1]
        
        rightMax = [[None, None]] * len(nums)
        rightMin = [[None, None]] * len(nums)
        
        max_so_far = nums[len(nums)-1]
        max_so_far_index = len(nums)-1
        min_so_far = nums[len(nums)-1]
        min_so_far_index = len(nums)-1
        
        for i in range(len(nums)-1, -1 , -1):
            if (nums[i] > max_so_far):
                max_so_far = nums[i]
                max_so_far_index = i
                
            if (nums[i] < min_so_far):
                min_so_far = nums[i]
                min_so_far_index = i
                
            rightMax[i] = [max_so_far, max_so_far_index]
            rightMin[i] = [min_so_far, min_so_far_index]
            
        # print(rightMax)
                
            
        for i in range(0, len(nums)-indexDifference):
            if (i+indexDifference >= len(nums)):
                break
            if (rightMax[i+indexDifference][0] - nums[i] >= valueDifference):
                ans[0] = i
                ans[1] = rightMax[i+indexDifference][1]
                return ans
            elif (nums[i] - rightMin[i+indexDifference][0] >= valueDifference):
                ans[0] = i
                ans[1] = rightMin[i+indexDifference][1]
                return ans
        
        return ans