class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        List<Integer>[] numbers = new List[nums.length + 1];
        Map<Integer, Integer> map = new HashMap<>();

        for (int num: nums){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int key: map.keySet()){
            int frequency = map.get(key);

            if (numbers[frequency] == null) numbers[frequency] = new ArrayList<>();

            numbers[frequency].add(key);
        }

        int[] res = new int[k];
        int i=0;


        for (int pos = numbers.length - 1; pos >= 0 && k > 0; pos--){
            if (numbers[pos] != null) {
                for (int n: numbers[pos]){
                    if (k == 0) break;

                    res[i] = n;
                    i++;
                    k--;
                }
            }
        }

        return res;
    }
}