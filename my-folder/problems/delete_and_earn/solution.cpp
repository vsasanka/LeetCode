class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> buckets(10001,0);
        
        for (int i=0; i<nums.size(); i++){
            buckets[nums[i]]++;
        }
        
        int take, takei, skip, skipi;
        
        take = buckets[1];
        skip = 0;
        
        for (int i=2; i<10001; i++){
            takei = skip + i*buckets[i];
            skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        
        return max(takei, skipi);
    }
};