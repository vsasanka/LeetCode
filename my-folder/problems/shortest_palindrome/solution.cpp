class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i=0;
        for (int j= n -1; j>= 0; j--){
            if (s[i] == s[j]){
                i++;
            }
        }
        
        if (i == n){
            return s;
        }
        
        string remaining_rev = s.substr(i);
        reverse(remaining_rev.begin(), remaining_rev.end());
        
        return remaining_rev + shortestPalindrome(s.substr(0,i)) + s.substr(i);
    }
};