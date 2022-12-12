class Solution {
public:
    long long recursion(vector<int>& nums, bool add, vector<vector<long long>> &dp, int index){
        
        if (index == nums.size()) return 0;
        
        if (dp[add][index] != 0) return dp[add][index];
        
        
        if (add){
            dp[add][index] = max(nums[index] + recursion(nums,!add, dp, index+1), \
                                recursion(nums, add, dp, index+1));
        }
        else{
            dp[add][index] = max(recursion(nums,!add, dp, index+1) - nums[index], \
                                recursion(nums, add, dp, index+1));
        }
        
        return dp[add][index];
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(2, vector<long long>(nums.size(),0));
        
        return recursion(nums, true, dp, 0);
    }
};