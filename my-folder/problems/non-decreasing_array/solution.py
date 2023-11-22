class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        first = nums[0]
        second = -float('inf')
        changes = 0

        for i in range(1, len(nums)):
            if nums[i] >= nums[i-1]:
                first = nums[i]
                second = nums[i-1]
            else:
                if nums[i] >= second:
                    second = nums[i]
                    first = nums[i]
                else:
                    nums[i] = first
                    second = first
                changes += 1

            if changes > 1:
                return False

        return True