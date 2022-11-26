class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        
        for (int i=1; i<triangle.size(); i++){
            int prev_left = dp[i-1][0];
            int prev_right = dp[i-1][triangle[i-1].size() - 1];
            
            vector<int> currRow(triangle[i].size());
            
            currRow[0] = prev_left + triangle[i][0];
            currRow[currRow.size()-1] = prev_right + triangle[i][currRow.size()-1];
            
            for (int j=1; j<currRow.size()-1; j++){
                currRow[j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
            
            dp.push_back(currRow);
        }
        
        return *min_element(dp[dp.size()-1].begin(), dp[dp.size()-1].end());
    }
};