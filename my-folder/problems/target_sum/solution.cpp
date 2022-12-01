class Solution {
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        vector<vector<int>> dp(2*sum+1, vector<int>(nums.size(), 0));
        
        dp[nums[0] + sum][0] = 1;
        dp[(-1)*nums[0] + sum][0] += 1;
        
        for (int i=1; i<nums.size(); i++){
            for (int j=0; j<2*sum+1; j++){
                int a1 = 0;
                int a2 = 0;
                if (j-nums[i] >= 0) a1 = dp[j-nums[i]][i-1];
                if (j+nums[i] < 2*sum+1) a2 = dp[j+nums[i]][i-1];
                dp[j][i] = a1 + a2;
            }
        }
        
        // for (int i=0; i<nums.size(); i++){
        //     for (int j=0; j<2*sum+1; j++){
        //         cout << dp[j][i] << " ";
        //     }
        //     cout << endl;
        // }
        
        if (target > sum || target + sum < 0) {
            return 0;
        }
        return dp[target+sum][nums.size()-1];
    }
};