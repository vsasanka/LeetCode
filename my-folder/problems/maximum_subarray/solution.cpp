class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], ans = nums[0];

        for (int i=1; i<nums.size(); i++){
            sum += nums[i];

            sum = max(nums[i], sum);

            ans = max(sum, ans);
        }

        return ans;
    }
};