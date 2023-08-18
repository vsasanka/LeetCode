class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> numSet = new HashSet<>();
        List<List<Integer>> numList = new ArrayList<>();

        Arrays.sort(nums);

        for (int i=0; i<nums.length; i++){
            int j = i+1;
            int k = nums.length - 1;

            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    numSet.add(Arrays.asList(nums[i],nums[j],nums[k]));
                    j++;
                    k--;
                }
                else if (sum < 0) j++;
                else k--;
            }
        }
        numList.addAll(numSet);
        return numList;
    }
}