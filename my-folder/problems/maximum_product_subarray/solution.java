class Solution {
    public int maxProduct(int[] nums) {
        int l = 1, r = 1;
        int ans = nums[0];
        int n = nums.length;

        for (int i=0; i<nums.length; i++){
            l = (l == 0) ? nums[i] : nums[i]*l;
            r = (r == 0) ? nums[n - 1 - i] : nums[n - 1 - i]*r;
            ans = Math.max(Math.max(l,r), ans);
        }

        return ans;
    }
}