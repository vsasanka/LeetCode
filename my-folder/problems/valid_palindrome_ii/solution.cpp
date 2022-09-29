class Solution {
public:
    
    bool isPalindrome(string &s){
        int i = 0, j = s.size() - 1;
        
        while (i<j){
            if (s[i] != s[j]){
                return false;
            }
            i++,j--;
        }
        
        return true;
    }
    
    bool check(string &s, int i, int j){
        string s1 = s.substr(0,i) + s.substr(i+1);
        string s2 = s.substr(0,j) + s.substr(j+1);
        
        bool one = isPalindrome(s1);
        bool two = isPalindrome(s2);
        
        return one || two;
    }
    
    bool validPalindrome(string s) {
        
        int i = 0, j = s.size() - 1;
        while(i<j && s[i] == s[j]){
            i++,j--;
        }
        
        if (i == j || j-i == 1){
            return true;
        }
        
        if (check(s,i,j)) return true;
        
        return false;
    }
};