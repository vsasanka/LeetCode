class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int prod = 1;
        Arrays.fill(ans, 1);

        for (int i=0; i<nums.length-1; i++){
            prod *= nums[i];
            ans[i+1] = prod;
        }

        prod = 1;

        for (int i=nums.length -1; i>0; i--){
            prod *= nums[i];
            ans[i-1] *= prod;
        }

        return ans;
    }
}