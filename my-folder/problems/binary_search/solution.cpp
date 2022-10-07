class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        
        while (left < right){
            mid = left + (right - left)/2;
            
            if (target == nums[mid]){
                return mid;
            }
            else if (nums[mid] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        if (nums[left] == target) return left;
        
        return -1;
    }
};