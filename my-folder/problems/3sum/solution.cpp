class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> ansset;
        int j,k, target;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-2; i++){
            
            j = i+1, k = nums.size() - 1;
            target = -1*(nums[i]);
            while (j < k){
//                 while (j+1 < k && nums[j] == nums[j+1]){
//                     j++;
//                 }
                
//                 while (k-1 > j && nums[k] == nums[k-1]){
//                     k--;
//                 }
                
                if (nums[j] + nums[k] == target){
                    ansset.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if (nums[j] + nums[k] < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        for (auto v: ansset){
            ans.push_back(v);
        }
        
        return ans;
    }
};