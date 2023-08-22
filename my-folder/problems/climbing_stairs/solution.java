class Solution {
    public int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int first = 1;
        int second = 2;

        while (n-2>0){
            int third = first + second;
            first = second;
            second = third;
            n--;
        }

        return second;
    }
}