class Solution {

public:
    int totalHammingDistance(vector<int>& nums) {
        
        int size = nums.size();
        int ones = 0;
        int totalzeros = 0;
        int sum = 0;
        
        while(true){
            
            ones = 0;
            totalzeros= 0;
            
            for (int i = 0; i<nums.size(); i++){
                if (nums[i]==0) totalzeros++;
                
                ones += nums[i]%2;
                nums[i] = nums[i] >> 1;
            }
            
            sum += (size - ones)*ones;
            
            if (totalzeros == size){
                return sum;
            }
        }
    }
};