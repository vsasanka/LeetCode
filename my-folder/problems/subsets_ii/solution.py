class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        self.ans = []
        
        nums.sort()
        
        def recursion(index, arr):
            # print (arr)
            self.ans.append(arr[:])
            # print (self.ans)
            
            for i in range(index, len(nums)):
                arr.append(nums[i])
                # self.ans.append(arr[:])
                # print (arr)
                recursion(i+1, arr)
                arr.pop()
        
        temp = []
        # self.ans.append(temp)
        recursion(0,temp)
        
        t = [tuple(l) for l in self.ans]
        
        u = (set(t))
        
        u = [list(a) for a in u]
        
        # print (u)
        
        return sorted(u)