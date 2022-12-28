class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        
        for (int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        int to_find;
        int ans = INT_MAX;
        
        for (int i=1; i<=n; i++){
            to_find = target + prefix[i-1];
            
            auto val = lower_bound(prefix.begin(), prefix.end(), to_find);
            
            if (val != prefix.end()){
                ans = min(ans, static_cast<int>(val - (prefix.begin() + i - 1)));
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};