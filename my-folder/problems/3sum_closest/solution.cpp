class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int j,k;
        int closest = INT_MAX;
        int sum=0;
        int diff;
        
        for (int i=0;i<nums.size()-2;i++){
            j = i+1;
            k = nums.size() - 1;
            
            while (j<k){
                diff = nums[i] + nums[j] + nums[k] - target;
                
                if (diff==0){
                    return target;
                }
                
                if (abs(diff) < closest){
                    closest = abs(diff);
                    sum = nums[i] + nums[j] + nums[k];
                }
                
                if (diff < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        return sum;
    }
};