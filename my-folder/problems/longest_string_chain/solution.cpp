class Solution {
    
private:
    bool static compare(string &a, string &b){
        return a.size() < b.size();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string,int> dp;
        
        sort(words.begin(), words.end(), compare);
        int res = 0;
        
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<words[i].size(); j++){
                string pre = words[i].substr(0,j) + words[i].substr(j+1);
                dp[words[i]] = max(dp[words[i]],dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[words[i]]);
        }
        
        return res;
    }
};