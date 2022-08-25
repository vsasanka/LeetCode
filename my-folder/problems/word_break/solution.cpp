class Solution {
    
private:
    bool presentInDict(string s, unordered_set<string> &wordDictSet){
        if (wordDictSet.find(s) != wordDictSet.end()){
            return true;
        }
        
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        
        for (auto i: wordDict){
            wordDictSet.insert(i);
        }
        
        vector<bool> dp(s.size()+1, false);
        
        dp[0] = true;
        
        for (int i=1; i<=s.size(); i++){
            for (int j=i-1; j>=0; j--){
                if (dp[j] && presentInDict(s.substr(j,i-j), wordDictSet)){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};

/*

vector - array .. vector<int> vec;

vec.push_back(1);

vec.push_back(45);

int array[2] = {1,2};

array[2] = 3; // error

set
unordered_map
unordered_set
*/