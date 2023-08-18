class Solution {
    public int characterReplacement(String s, int k) {
        Map<Character, Integer> mp = new HashMap<>();

        int i=0;
        int maxUnique = 0;

        for (int j=0; j<s.length(); j++){
            int val = mp.getOrDefault(s.charAt(j), 0) + 1;
            mp.put(s.charAt(j), val);
            maxUnique = Math.max(maxUnique, val);

            if (j-i+1 > maxUnique + k){
                int val2 = mp.get(s.charAt(i));
                if ( val2 == 1) mp.remove(s.charAt(i));
                else mp.put(s.charAt(i), val2 - 1);
                i++;
            }
        }

        return Math.min(maxUnique + k, s.length());
    }
}