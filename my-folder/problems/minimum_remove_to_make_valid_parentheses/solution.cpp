class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(') balance += 1;
            else if (s[i] == ')') balance -= 1;
            
            if (balance < 0){
                s[i] = '.';
                balance = 0;
            }
        }
        
        // cout << ans << endl;
        
        balance = 0;
        
        for (int i=s.size() - 1; i>=0; i--){
            if (s[i] == ')') balance += 1;
            else if (s[i] == '(') balance -= 1;
            
            if (balance < 0){
                s[i] = '.';
                balance = 0;
            }
        }
        
        for (int i=0; i<s.size(); i++){
            if (s[i] == '.'){
                s = s.substr(0,i) + s.substr(i+1);
                i--;
            }
        }
        
        return s;
    }
};