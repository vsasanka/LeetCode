class Solution {
public:
    int recursion(vector<int>& nums, int i, int j, int target){

        while (i<=j){
            int mid = i + (j-i)/2;

            if (nums[mid] == target){
                return mid;
            }
            else{
                return max(recursion(nums, i, mid-1, target), recursion(nums, mid+1, j, target));
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        return recursion(nums, left, right, target);
    }
};