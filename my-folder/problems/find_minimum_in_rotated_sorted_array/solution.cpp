class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        while(left<right){
            mid = left + (right - left)/2;
            // cout << nums[mid] << " ";
            
            if (nums[mid] < nums[left] || nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};