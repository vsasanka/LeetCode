class Solution {
    public int maxArea(int[] height) {
        int a = 0, b = height.length - 1;
        int ans = 0;

        while (a < b){
            ans = Math.max(ans, Math.min(height[a], height[b])*(b - a));
            System.out.println(Integer.toString(ans) + " " + Integer.toString(a) + " " + Integer.toString(b));

            if (height[a] < height[b]) a++;
            else b--;
        }

        return ans;
    }
}