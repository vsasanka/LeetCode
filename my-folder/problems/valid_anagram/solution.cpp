class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> maps;
        unordered_map<char,int> mapt;
        
        if (s.size() != t.size()){
            return false;
        }
        
        for (int i=0; i<s.size(); i++){
            if (maps.find(s[i])==maps.end()){
                maps[s[i]] = 1;
            }
            else{
                maps[s[i]]++;
            }
            
            if (mapt.find(t[i])==mapt.end()){
                mapt[t[i]] = 1;
            }
            else{
                mapt[t[i]]++;
            }
        }
        
        if (mapt.size() != maps.size()){
            return false;
        }
        
        for (auto e : maps){
            if (e.second != mapt[e.first]){
                return false;
            }
        }
        
        return true;
    }
};