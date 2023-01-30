class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int l = 1, r = 1, ans = nums[0];
        int n = nums.size();
        
        for (int i=0; i<nums.size(); i++){
            l = (l == 0) ? nums[i] : l*nums[i];
            r = (r == 0) ? nums[n-i-1] : r*nums[n-i-1];
            ans = max(ans, max(l,r));
        }
        
        return ans;
    }
};