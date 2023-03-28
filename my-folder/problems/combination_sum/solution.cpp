class Solution {
public:
    void recursion(vector<vector<int>> &ans, vector<int>& candidates, int index, int sum, int &target, vector<int>& combination){
        
        if (sum > target) return ;

        if (sum == target) ans.push_back(combination);

        int n = candidates.size();

        for (int i=index; i<n; i++){
            combination.push_back(candidates[i]);
            recursion(ans, candidates, i, sum + candidates[i], target, combination);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        recursion(ans, candidates, 0, 0, target, comb);

        return ans;
    }
};