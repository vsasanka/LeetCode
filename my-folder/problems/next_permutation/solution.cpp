class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int replaceIndex = -1;
        
        for (int i=n-1; i>=1; i--){
            if (nums[i] > nums[i-1]){
                replaceIndex = i-1;
                break;
            }
        }
        
        if (replaceIndex == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        // find the value immediately greater than nums[replaceIndex]
        sort(nums.begin() + replaceIndex + 1, nums.end());
        
        for (int i=replaceIndex+1; i<n; i++){
            if (nums[i] > nums[replaceIndex]){
                int temp = nums[i];
                nums[i] = nums[replaceIndex];
                nums[replaceIndex] = temp;
                break;
            }
        }
        
        sort(nums.begin() + replaceIndex + 1, nums.end());
        return ;
    }
};