class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max = nums[0];
        int local = 0;
        
        for (int i=0;i<nums.size();i++){
            local += nums[i];
            
            if (local<=0){
                local=0;
            }
            else if (local>max){
                max = local;
            }
            if (nums[i]>max){
                max = nums[i];
            }
        }
        
        return max;
    }
};