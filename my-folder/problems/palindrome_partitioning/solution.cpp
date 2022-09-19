class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        
        vector<string> currentList;
        vector<vector<string>> res;
        
        dfs(s,0,currentList,dp,res);
        
        return res;
    }
    
    void dfs(string &s, int start, vector<string> &currentList, vector<vector<bool>>&dp, vector<vector<string>> &res){
        if (start >= s.size()){
            res.push_back(currentList);
            return ;
        }
        
        for (int i=start; i<s.size(); i++){
            if (s[start]==s[i] && ((i-start <=1) || dp[start+1][i-1]) ){
                dp[start][i] = true;
                currentList.push_back(s.substr(start, i - start + 1));
                dfs(s,i+1, currentList, dp, res);
                currentList.pop_back();
            }
        }
    }
};