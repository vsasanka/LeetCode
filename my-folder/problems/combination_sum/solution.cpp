class Solution {
    
private:
    void recursion(vector<int> &currComb, vector<int> &candidates, int currSum, int currIndex, vector<vector<int>> &ans, int target){
        if (currSum==target){
            ans.push_back(currComb);
            return ;
        }
        if (currSum>target){
            return ;
        }
        
        for (int i=currIndex; i<candidates.size(); i++){
            currSum += candidates[i];
            currComb.push_back(candidates[i]);
            recursion(currComb, candidates, currSum, i, ans, target);
            currComb.pop_back();
            currSum -= candidates[i];
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        
        int sum = 0;
        int currIndex = 0;
        
        recursion(currComb, candidates, sum, currIndex, ans, target);
        return ans;
    }
};