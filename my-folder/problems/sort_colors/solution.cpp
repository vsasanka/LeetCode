class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ones = 0, twos = 0, zeros = 0;
        
        for (int i: nums){
            if (i == 0){
                zeros++;
            }
            else if (i == 1){
                ones++;
            }
            else if (i == 2){
                twos++;
            }
        }
        
        int i=0;
        
        while (zeros){
            nums[i] = 0;
            i++;
            zeros--;
        }
        
        while (ones){
            nums[i] = 1;
            ones--;
            i++;
        }
        
        while (twos){
            nums[i] = 2;
            i++;
            twos--;
        }
    }
};