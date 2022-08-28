class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int l = 0, r = 0;
        int res = nums[0];
        
        for (int i=0; i<nums.size(); i++){
            l = (l?l:1) *nums[i];
            r = (r ? r:1)*nums[nums.size() - 1 - i];
            
            res = max(res, max(l,r));
        }
        
        return res;
    }
};

/*

9 5 4 3 2

9 5 4 0 2 3 4 

9 -5 4 0 2 3 4 -1 -9

-9 -3 -4 0

-2

2

0

*/