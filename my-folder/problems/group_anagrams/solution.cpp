class Solution {
public:
    string anaString(string input){
        string ans = "";
        
        for (int i=0; i<26; i++){
            ans += '0';
        }

        for (char c: input){
            ans[c-'a'] = (ans[c-'a'] - '0' + 1) + '0';
        }

        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramMap;

        for (int i=0; i<strs.size(); i++){
            anagramMap[anaString(strs[i])].push_back(strs[i]);
        }

        for (auto v: anagramMap){
            vector<string> anas;

            for (string s: v.second){
                anas.push_back(s);
            }

            ans.push_back(anas);
        }

        return ans;
    }
};

