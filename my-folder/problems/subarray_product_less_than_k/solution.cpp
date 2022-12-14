class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int count = 0;
        int tempProd = 1;
        int j = 0;
        
        for (int i=0; i<nums.size(); i++){
            if (i > j) j = i;
            
            while (j < nums.size() && tempProd*nums[j] < k){
                cout << nums[j] << " ";
                tempProd *= nums[j];
                j++;
            }
            
            count += j - i;
            tempProd /= nums[i];
            
            if (tempProd == 0){
                tempProd = 1;
            }
        }
        
        return count;
    }
};