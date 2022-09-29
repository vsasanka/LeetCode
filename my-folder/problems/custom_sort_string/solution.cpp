class Solution {
public:
    
    string customSortString(string order, string s) {
        
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        string res = "";
        
        for (int i=0; i<order.size(); i++){
            mp2[order[i]]++;
        }
        
        string ressuf = "";
        
        for (int i=0; i<s.size(); i++){
            mp[s[i]]++;
            
            if (mp2.find(s[i]) == mp2.end()){
                ressuf += s[i];
            }
        }
        
        for (int i=0; i<order.size(); i++){
            if (mp.find(order[i]) != mp.end()){
                for (int j=0; j<mp[order[i]]; j++){
                    res += order[i];
                }
            }
        }
        
        return res + ressuf;
    }
};