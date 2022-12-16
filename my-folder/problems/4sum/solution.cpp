class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                int k = j+1;
                int l = nums.size() - 1;
                
                
                while (k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target){
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if (sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
};