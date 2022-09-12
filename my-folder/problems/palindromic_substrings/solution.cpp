class Solution {
public:
    
    void palindromes(string &s, int left, int right, int &count){
        while ((left >=0 && right < s.size()) && s[left] == s[right] ){
            count++;
            left--;
            right++;
        }
    }
    
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i=0; i<s.size(); i++){
            palindromes(s, i,i, count);
            palindromes(s, i, i+1, count);
        }
        
        return count;
    }
};