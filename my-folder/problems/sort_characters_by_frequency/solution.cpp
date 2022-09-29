class Solution {
public:
    
    bool static compare(pair<char,int>&a, pair<char,int> &b){
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for (int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        vector<pair<char,int>> pairs;
        
        for (auto m: mp){
            pairs.push_back(m);
        }
        
        sort(pairs.begin(), pairs.end(), compare);
        
        string res = "";
        
        for (auto p: pairs){
            for (int i=0; i<p.second; i++){
                res += p.first;
            }
        }
        
        return res;
    }
};