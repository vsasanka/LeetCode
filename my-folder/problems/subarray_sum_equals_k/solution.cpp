class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int> sumIndex;
        
        sumIndex[0] = 1;
        
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            
            if (sumIndex.find(sum - k) != sumIndex.end()){
                count += sumIndex[sum - k];
            }
            
            if (sumIndex.find(sum) != sumIndex.end()){
                sumIndex[sum]++;
            }
            else{
                sumIndex[sum] = 1;
            }
        }
        
        return count;
    }
};