class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        i = j = 0;
        int n = nums.size();
        int temp;
        
        while (i < n && j < n){
            if (nums[j] == 0){
                j++;
                continue;
            }
            else if (nums[i] != 0){
                i++;
                continue;
            }
            
            if ( i < j ){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            }
            else{
                j = i + 1;
            }
        }
    }
};