class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(self, l, m, r):
            n1 = m - l + 1
            n2 = r - m

            res = [0 for _ in range(n1+n2)]

            i1 = l
            i2 = m + 1
            i = 0

            while i1 < l + n1 and i2 < m + 1 + n2:
                if (nums[i1] < nums[i2]):
                    res[i] = nums[i1]
                    i1 += 1
                else:
                    res[i] = nums[i2]
                    i2 += 1
                i += 1

            while i1 < l + n1:
                res[i] = nums[i1]
                i1 += 1
                i += 1

            while i2 < m + 1 + n2:
                res[i] = nums[i2]
                i2 += 1
                i += 1
            
            for i in range(len(res)):
                nums[i+l] = res[i]
        
        def mergeSplit(self, l, r):
            if l < r:
                m = (l + r) // 2
                mergeSplit(self, l, m)
                mergeSplit(self, m+1, r)
                merge(self, l, m, r)

        mergeSplit(self, 0, len(nums)-1)

        return nums