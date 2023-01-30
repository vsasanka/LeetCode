class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while(nums[left] > nums[right]){
            mid = left + (right - left)/2;
            
            if (nums[left] > nums[mid]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};