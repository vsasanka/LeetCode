class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        for (char c: s){
            if ('A' <= c && c <= 'Z'){
                ans += tolower(c);
            }
            else if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9')){
                ans += c;
            }
        }

        int l = 0, r = ans.size()-1;

        while (l < r){
            if (ans[l] != ans[r]){
                return false;
            }
            l++, r--;
        }

        return true;
    }
};