class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size()==1){
            return nums[0];
        }
        
        // vector<int> dp(nums.size(), 0);
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
        
        int left = nums[0];
        int right = max(nums[0], nums[1]);
        int temp;
        
        if (nums.size()==2){
            return right;
        }
        
        for (int i=2; i<nums.size(); i++){
            // dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            temp = right;
            right = max(left + nums[i], right);
            left = temp;
        }
        
        return right;
    }
};

/*

2 3 4 3 9  3  4  5   1  3 

2 3 6 6 15 15 19 20

*/