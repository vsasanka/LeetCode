class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int ones = 0;
        int zeros = 0;
        
        for (char c: s){
            if (c == '1') ones++;
            else zeros++;
        }
        
        for (int i=0; i<s.size(); i++){
            
            if (s[i] == '0' && target[i] == '1'){
                if (ones > 0) {
                    ones++;
                    s[i] = '1';
                }
                else{
                    return false;
                }
            }
        }
        
        for (int i=0; i<s.size(); i++){
            if (s[i] == '1' && target[i] == '0'){
                if (ones > 1) ones--;
                else return false;
            }
        }
        
        
        return true;
    }
};