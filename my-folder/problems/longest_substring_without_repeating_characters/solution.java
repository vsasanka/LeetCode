class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> charSet = new HashSet<>();
        int i=0;
        int ans = 0;

        for (int j=0; j<s.length(); j++){
            while (charSet.contains(s.charAt(j))){
                charSet.remove(s.charAt(i));
                i++;
            }
            charSet.add(s.charAt(j));
            ans = Math.max(ans, j - i + 1);
        }

        return ans;
    }
}