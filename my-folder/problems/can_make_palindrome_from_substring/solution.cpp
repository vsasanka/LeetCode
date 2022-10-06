class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        vector<int> count(26, 0);
        int changes;
        vector<bool> ans;
        vector<vector<int> > dp;
        dp.push_back(count);
        
        for (int i=0; i<s.size(); i++){
            count[s[i]-'a']++;
            
            dp.push_back(count);
        }
        
        for (auto &q: queries){
            changes = 0;
            
            for (int i=0; i<26; i++){
                count[i] = (dp[q[1] + 1][i] - dp[q[0]][i])%2; 
            }
            
            for (int i=0; i<26; i++){
                changes += count[i];
            }
            
            if (changes/2 <= q[2]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            
        }
        
        return ans;
    }
};