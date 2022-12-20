class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int r = nums.size() - 1;
        int l = 0;
        int ans = 0;
        int MOD = 1000000007;
        
        sort(nums.begin(), nums.end());
        
        vector<int> pows(nums.size(), 1);
        for (int i = 1 ; i < nums.size() ; ++i)
            pows[i] = pows[i - 1] * 2 % MOD;
        
        while (l < nums.size()){
            
            while (l <= r && nums[l] + nums[r] > target){
                r--;
            }
            
            if (l <= r){
                ans += pows[r-l];
                ans %= MOD;
            }
            l++;
        }
        
        return ans;
    }
};