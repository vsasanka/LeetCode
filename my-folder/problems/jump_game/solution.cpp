class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = nums[0];
        int n = nums.size();

        for (int i=0; i<n; i++){
            jump = max(nums[i] + i, jump);

            if (i == n - 1) return true;

            if (jump <= i) return false;
        }

        return true;
    }
};