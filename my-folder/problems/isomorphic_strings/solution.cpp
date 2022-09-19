class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> mp2;
        
        for (int i=0; i<s.size(); i++){
            auto mt = mp2.find(t[i]);
            auto ms = mp.find(s[i]);
            
            if (ms != mp.end() && mp[s[i]] != t[i]){
                return false;
            }
            
            if (mt != mp.end() && mp2[t[i]] != s[i]){
                return false;
            }
            
            if (ms == mp.end()){
                mp[s[i]] = t[i];
            }
            
            if (mt == mp2.end()){
                mp2[t[i]] = s[i];
            }
        }
        
        return true;
    }
};