class Solution {
    
    vector<vector<int>> result;
    int k;
    
private:
    void recursion(vector<int>& nums, int index, vector<int>& curr){
        
        if (index==k){
            result.push_back(curr);
            return ;
        }
        
       for (int i=index;i<nums.size();i++){
            vector<int> currcopy(curr.begin(),curr.end());
           currcopy.push_back(nums[i]);
           recursion(nums,i+1,currcopy);
       }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;
        for (k=0;k<=nums.size();k++){
            recursion(nums,0,curr);
        }
        
        return result;
        
    }
};