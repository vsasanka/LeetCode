class Solution {
public:
    bool isPalindrome(string s) {
        
        int i,j;
        i = 0;
        j = s.size()-1;
        while (i<j){
            if ( ('a'<=s[i] && s[i]<='z') ){
                
            }
            else if (('A'<=s[i] && s[i]<='Z')){
                s[i] = s[i] + ('a' - 'A');
            }
            else if (('0'<=s[i] && s[i]<='9')){
                
            }
            else{
                i++;
                continue;
            }
            
            if ( ('a'<=s[j] && s[j]<='z') ){
                
            }
            else if (('A'<=s[j] && s[j]<='Z')){
                s[j] = s[j] + ('a' - 'A');
            }
            else if (('0'<=s[j] && s[j]<='9')){
                
            }
            else{
                j--;
                continue;
            }
            
            if (s[i]!=s[j]){
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};