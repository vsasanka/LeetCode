class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()){
            return false;
        }
        
        if (s == goal){
            vector<int> fre(26,0);
            
            for (int i=0; i<s.size(); i++){
                fre[s[i] - 'a']++;
                
                if (fre[s[i] - 'a'] > 1){
                    return true;
                }
            }
            
            return false;
        }
        
        vector<int> mm;
        
        for (int i=0; i<s.size(); i++){
            if (s[i] != goal[i]){
                mm.push_back(i);
            }
            
            if (mm.size() > 2){
                return false;
            }
        }
        
        if (mm.size() != 2){
            return false;
        }
        
        if (s[mm[0]] == goal[mm[1]] && s[mm[1]] == goal[mm[0]]){
            return true;
        }
        
        return false;
    }
};