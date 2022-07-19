class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int leftsum = 0, rightsum = 0;
        
        vector<int> contsum;

        for (int i=0; i<nums.size(); i++){
            leftsum += nums[i];
            contsum.push_back(leftsum);
        }
        
        for (int i=0; i<nums.size(); i++){
            if (contsum[i] - nums[i] == contsum[nums.size()-1] - contsum[i]){
                return i;
            }
        }
        
        return -1;
    }
};