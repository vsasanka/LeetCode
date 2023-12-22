class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        n, k = len(nums), len(nums)
        count = 1
        i = 1

        if n == 1:
            return 1

        while i < n:
            # print (i, k)
            if i >= k:
                break

            if nums[i - 1] == nums[i]:
                count += 1

                if count > 2:
                    # print (i, count)
                    for j in range(i, n):
                        if j + 1 < n:
                            nums[j] = nums[j + 1]
                    k -= 1
                    i -= 1
            else:
                count = 1

            i += 1

        return k