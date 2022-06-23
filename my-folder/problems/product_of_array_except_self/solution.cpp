class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1;
        vector<int> ans;
        ans.push_back(1);
        
        for (int i=1; i<nums.size(); i++){
            prod *= nums[i-1];
            ans.push_back(prod);
        }
        
        int revprod = 1;
        for (int i= nums.size()-2; i>=0; i--){
            revprod *= nums[i+1];
            ans[i] *= revprod;
        }
        
        return ans;
    }
};