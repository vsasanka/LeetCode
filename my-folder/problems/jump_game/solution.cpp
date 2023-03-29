class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int currPosition = 0;

        for (int i=0; i<nums.size()-1; i++){
            currPosition = i+1;
            maxJump = max(nums[i]+currPosition, maxJump);

            if (currPosition >= maxJump) return false;
        }

        return true;
    }
};