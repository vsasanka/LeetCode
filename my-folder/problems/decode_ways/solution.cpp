class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;

        // if (s[0] == '0') return 0;

        for (int i=0; i<s.size(); i++){
            if (s[i] == '0') return 0;
            if (i+1 < s.size() && s[i+1] == '0'){
                if (s[i] == '1' || s[i] == '2'){
                    dp[i+1] = dp[i+2] = dp[i];
                    i++;
                    continue;
                }
                else{
                    return 0;
                }
            }

            dp[i+1] = dp[i];

            if (i-1 >= 0){
                if (s[i-1] == '1' || (s[i-1] == '2' && '1' <= s[i] && s[i] <= '6')){
                    dp[i+1] += dp[i-1];
                }
            }
        }

        return dp[s.size()];
    }
};