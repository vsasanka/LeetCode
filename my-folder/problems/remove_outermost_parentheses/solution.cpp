class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string ans = "";
        int left = 0;
        
        for (int i=0; i<s.size(); i++){
            balance += s[i] == '(' ? 1:-1;
            
            if (balance == 0){
                if (i-left > 1) {
                    ans += s.substr(left+1, i-left-1);
                }
                
                left = i+1;
            }
        }
        
        return ans;
    }
};