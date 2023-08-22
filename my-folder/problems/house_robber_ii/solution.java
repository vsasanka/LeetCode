class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);

        int first = nums[0];
        int second = Math.max(nums[0], nums[1]);
        int ans = second;

        for (int i=2; i<nums.length-1; i++){
            int third = Math.max(first + nums[i], second);
            ans = Math.max(third, ans);

            first = second;
            second = third;
        }

        first = nums[1];
        second = Math.max(nums[1], nums[2]);
        ans = Math.max(ans, second);

        for (int i=3; i<nums.length; i++){
            int third = Math.max(first + nums[i], second);
            ans = Math.max(third, ans);

            first = second;
            second = third;
        }

        return ans;
    }
}