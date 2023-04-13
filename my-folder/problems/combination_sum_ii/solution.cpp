class Solution {
public:
    void recursion(vector<vector<int>> &combinations, int index, vector<int> &combo, int sum, int &target, vector<int> &candidates){
        if (sum > target) {
            // cout << 11 << endl;
            return ;
        }

        if (sum == target) {
            // cout << 22 << endl;
            combinations.push_back(combo);
            return ;
        }

        if (index == candidates.size()) {
            // cout << sum << endl;
            return ;
        }

        for(int i = index; i < candidates.size(); i++) {
            if(i == index || candidates[i] != candidates[i - 1]) {
                combo.push_back(candidates[i]);
                recursion(combinations, i+1, combo, sum + candidates[i], target, candidates);
                combo.pop_back();
            }
        }

        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> combinations;
       vector<int> combo;

       sort(candidates.begin(), candidates.end());

       recursion(combinations, 0, combo, 0, target, candidates);

       return combinations;
    }
};