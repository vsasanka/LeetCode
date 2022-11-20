class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        int count = 0;
        
//         for (int i=0; i<nums.size(); i++){
//             if (i+1 < nums.size() && nums[i] == nums[i+1]) continue;
            
//             for (int j=i+1; j< nums.size(); j++){
//                 if (j+1 < nums.size() && nums[j] == nums[j+1]) continue;
                
//                 if (j+1 < nums.size() && nums[i] != nums[j+1]){
//                     count++;
//                 }
//             }
//         }
        
        for (int i=0; i<nums.size()-2; i++){
            for (int j=i+1; j<nums.size()-1; j++){
                for (int k=j+1; k<nums.size(); k++){
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i]) count++;
                }
            }
        }
        
        return count;
    }
};