class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        if (nums.size() == 1){
            return nums[0];
        }
        int first = nums[1];
        int second = max(nums[1], nums[2]);
        int temp;
        
        for (int i=3; i<nums.size(); i++){
            temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }
        
        int max1 = second;
        
        first = nums[0];
        second = max(nums[0], nums[1]);
        
        for (int i=2; i<nums.size()-1; i++){
            temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }
        
        return max(max1, second);
    }
};