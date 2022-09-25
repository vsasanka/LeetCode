class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int i = 1;
        int len_temp = 1;
        int len = 1;
        int bwa = nums[0];
        int bwa_max = nums[0];
        
        while(i<nums.size()){
            if (nums[i] == nums[i-1]){
                len_temp++;
                i++;
                continue;
            }
            
            if (nums[i-1] == bwa_max){
                len = max(len, len_temp);
            }
            
            if (nums[i-1] > bwa_max){
                bwa_max = nums[i-1];
                len = len_temp;
            }
            
            bwa = nums[i];
            len_temp = 1;
            
            i++;
        }
        
        if (len_temp == 1){
            if (nums[nums.size() - 1] > bwa_max){
                bwa_max = nums[i-1];
                len = len_temp;
            }
        }
        
        if (len_temp > 1){
            if (nums[nums.size() - 1] >= bwa_max){
                bwa_max = nums[nums.size() - 1];
                // cout << len_temp << endl;
                len = max(len, len_temp);
                
//                 bwa = nums[i];
//                 len_temp = 1;
            }
        }
        
        return len;
    }
};