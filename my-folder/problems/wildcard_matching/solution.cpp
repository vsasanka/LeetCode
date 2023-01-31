class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));

        dp[0][0] = true;

        for (int i=1; i<=p.size(); i++){
            if (p[i-1] == '*'){
                dp[i][0] = dp[i-1][0];
            }
        }

        for (int i=1; i<=p.size(); i++){
            for (int j=1; j<=s.size(); j++){
                if (p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[i-1] == '*'){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                    int k = j;
                    while (!dp[i][j] && k >= 0){
                        dp[i][j] = dp[i][j] || dp[i][k--];
                    }
                }
            }
        }

        return dp[p.size()][s.size()];
    }
};


/*

abcdded
ab?d*d

  - a b c d d e d
- T f f f f f f f              
a f T F F F F F F          
b f f T F f f f f        
? f f f T f f f f        
d f f f f T F f f        
* f f f f T T T T        
d f               

*/