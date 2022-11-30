class Solution {
private:
    void recursion(vector<int>& nums, int &target, int sum, int i, int &ans){
        if (i >= nums.size()) {
            if (sum == target){
                ans++;
            }
            return ;
        }
        
        recursion(nums, target, sum - nums[i], i+1, ans);
        recursion(nums, target, sum + nums[i], i+1, ans);
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        
        recursion(nums, target, 0, 0, ans);
        
        return ans;
    }
};