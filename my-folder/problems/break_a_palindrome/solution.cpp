class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        
        if (n <= 1){
            return "";
        }

        for (int j=0; j<n; j++){
            if (n%2==1 && j == n/2){
                continue;
            }
            if (palindrome[j] != 'a'){
                return palindrome.substr(0,j) + 'a' + palindrome.substr(j+1);
            }
        }
        
        return palindrome.substr(0,n-1) + 'b';

        return "";
    }
};