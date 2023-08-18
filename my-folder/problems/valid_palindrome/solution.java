class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        System.out.println(s);
        int n = s.length();

        int left = 0, right = n-1;

        while (left < right){
            char l = s.charAt(left);
            char r = s.charAt(right);

            if (!( ('a' <= l && l <= 'z') || ('0' <= l && l <= '9') )) {
                left++;
                continue;
            }
            if (!( ('a' <= r && r <= 'z') || ('0' <= r && r <= '9'))) {
                right--;
                continue;
            }

            if (l != r) return false;

            left++; right--;
        }

        return true;
    }
}