class Solution {
    public int maxSubArray(int[] nums) {
        int temp = 0;
        int ans = Integer.MIN_VALUE;

        for (int i=0; i<nums.length; i++){
            temp += nums[i];
            temp = Math.max(temp, nums[i]);
            ans = Math.max(ans, temp);
        }

        return ans;
    }
}