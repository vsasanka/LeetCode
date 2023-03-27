class Solution {
public:
    int left, right;
    int palindromeSize(int i, int j, string s){
        while (i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }

        left = i;
        right = j;

        return j - i - 1;
    }

    string longestPalindrome(string s) {
        int maxPalLen = 0;
        int palLen1, palLen2;
        string ans = "";

        for (int i=0; i<s.size(); i++){
            palLen1 = palindromeSize(i,i,s);

            if (palLen1 > maxPalLen){
                ans = s.substr(left+1, palLen1);
                maxPalLen = palLen1;
            }

            palLen2 = palindromeSize(i,i+1,s);

            if (palLen2 > maxPalLen){
                ans = s.substr(left+1, palLen2);
                maxPalLen = palLen2;
            }
        }

        return ans;
    }
};