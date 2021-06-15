class Solution {
    
private:
    int recursion(vector<int>&nums, int left, int right, int target){
        if ( left > right){
            return -1;
        }
        
        int mid = (left + right)/2;
        
        if (nums[mid] == target){
            return mid;
        }
        else{
            return max(recursion(nums, left, mid - 1,target), recursion(nums, mid + 1, right ,target));
        }
    }
    
public:
    int search(vector<int>& nums, int target) {
        // (n - pi + target_index)%n
        return recursion(nums, 0, nums.size()-1, target);
    }
};