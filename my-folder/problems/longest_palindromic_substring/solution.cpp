class Solution {
    
private: 
    bool isPalindrome(string& s, int left, int right){
        while(left<right){
            if (s[left]!=s[right]){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        
        return true;
}
    
public:
    string longestPalindrome(string s) {
        int i,j;
        string maxstring=s.substr(0,1);
        
        for (i=0;i<s.size()-maxstring.size();i++){
            for (j=s.size()-1;j>i;j--){
                if (s[i]==s[j] && isPalindrome(s, i,j) && maxstring.size() < (j-i+1)){
                    // cout << s[i] << " " << s[j] << " ";
                    maxstring=s.substr(i,j-i+1);
                    break;
                }
            }
        }
        
        return maxstring;
    }
};