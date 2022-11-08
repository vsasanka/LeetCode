class Solution {
public:
    string makeGood(string s) {
        
        for (int i=0; i+1<s.size(); i++){
            if ((s[i] -'a' == s[i+1] - 'A') || (s[i] -'A' == s[i+1] - 'a')){
                return makeGood(s.substr(0,i) + s.substr(i+2));
            }
        }
        
        return s;
    }
};