class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid, rmid;
        int n = nums.size();

        while (low < high){
            mid = (low + high)/2;

            if (nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }

        int offset = low;

        low = 0, high = nums.size() - 1;

        while (low <= high){
            mid = (low + high)/2;
            rmid = (mid + offset)%n;

            if (nums[rmid] == target){
                return rmid;
            }
            else if (nums[rmid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};