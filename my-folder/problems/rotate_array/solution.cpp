class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        
        vector<int> nums_dup;
        
        for (int i=0;i<len;i++){
            nums_dup.push_back(0);
        }
        
        for (int i=0;i<len;i++){
            nums_dup[(i+k)%len]=nums[i];
            
        }
        
        for (int i=0;i<len;i++){
            nums[i]=nums_dup[i];
        }
    }
};