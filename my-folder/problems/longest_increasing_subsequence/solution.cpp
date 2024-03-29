class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1);
        
        for (int i=0; i<nums.size(); i++){
            for (int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

// 1 2 3 4 3 2 1 5 6 7 8 

//                 2 1 0