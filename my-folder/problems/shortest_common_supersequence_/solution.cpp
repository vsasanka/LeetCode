class Solution {
public:
    string lcs(string str1, string str2){
        vector<vector<string>> dp(str1.size() + 1, vector<string> (str2.size() + 1, ""));
        
        for (int i=0; i<str1.size(); i++){
            for (int j=0; j<str2.size(); j++){
                if (str1[i] == str2[j]){
                    dp[i+1][j+1] = dp[i][j] + str1[i];
                }
                else{
                    dp[i+1][j+1] = (dp[i+1][j].size() > dp[i][j+1].size()) ? dp[i+1][j] : dp[i][j+1];
                }
            }
        }
        
        return dp[str1.size()][str2.size()];
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        string leastcs = lcs(str1, str2);
        int i = 0, j = 0;
        string res = "";
        
        for (auto c: leastcs){
            while (i< str1.size() && str1[i] != c){
                res += str1[i++];
            }
            while (j < str2.size() && str2[j] != c){
                res += str2[j++];
            }
            
            res += c;
            i++;
            j++;
        }
        
        while (i< str1.size()){
            res += str1[i++];
        }
        while (j < str2.size()){
            res += str2[j++];
        }
        
        return res;
    }
    
    
};