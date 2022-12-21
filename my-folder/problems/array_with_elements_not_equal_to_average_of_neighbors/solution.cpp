class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i+=2){
            if (i+1 < nums.size()){
                int t = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = t;
            }
        }
        
        return nums;
    }
};
/*

1 2 3 4 5

2 1 4 3 5
*/

    