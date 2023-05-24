class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size();
        int k = last;

        for (int i=last-1; i>=0 ;i--){
            if (nums[i] == val){
                last--;
                int temp = nums[i];
                nums[i] = nums[last];
                nums[last] = temp;
                k--;
            }
        }

        return k;
    }
};