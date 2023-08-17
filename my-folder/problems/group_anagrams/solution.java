class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groupAnagrams = new HashMap<>();

        for (String str: strs){
            char[] charArr = str.toCharArray();
            Arrays.sort(charArr);
            String sortedStr = String.valueOf(charArr);

            if (!groupAnagrams.containsKey(sortedStr)){
                groupAnagrams.put(sortedStr, new ArrayList<>());
            }
            groupAnagrams.get(sortedStr).add(str);
        }

        return new ArrayList<>(groupAnagrams.values());
    }
}