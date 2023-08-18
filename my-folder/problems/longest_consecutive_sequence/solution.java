class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> mainSet = new HashSet<>();
        int ans = 0;

        for (int n : nums){
            mainSet.add(n);
        }

        for (int n: nums){
            if (!mainSet.contains(n)) continue;

            mainSet.remove(n);

            int left = n-1, right = n+1;

            while (mainSet.contains(left)){
                mainSet.remove(left);
                left--;
            }

            while (mainSet.contains(right)){
                mainSet.remove(right);
                right++;
            }

            ans = Math.max(ans, right - left - 1);
        }

        return ans;
    }
}