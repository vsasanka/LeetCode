class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> freq;
        for (int i=0;i<nums.size();i++){
            if (freq.find(nums[i])==freq.end()){
                freq.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};