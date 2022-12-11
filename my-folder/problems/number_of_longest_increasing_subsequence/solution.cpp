class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        if (nums.size() == 1) return 1;
        
        vector<int> dp(nums.size(), 1);
        vector<int> freqCount(nums.size(),1);
        int longestLen = 0;
        int llCount = 0;
        
        for (int i=1; i<nums.size(); i++){
            int j = i-1;
            
            while(j >= 0){
                if (nums[j] < nums[i]){
                    if (dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        freqCount[i] = freqCount[j];
                    }
                    else if (dp[i] == dp[j]+1){
                        freqCount[i] += freqCount[j];
                    }
                }
                j--;
            }
            
            if (longestLen == dp[i]){
                llCount += freqCount[i];
            }
            else if (longestLen < dp[i]){
                longestLen = dp[i];
                llCount = freqCount[i];
            }
        }
        
        if (longestLen == 1){
            return nums.size();
        }
        
//         for (auto i: dp){
//             cout << i << " ";
//         }
//         cout << endl;
        
//         for (auto i: freqCount){
//             cout << i << " ";
//         }
        
        return llCount;
    }
};