class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        
        for (char c: s){
            mp[c]++;
        }
        
        int palsize = 0;
        int flag = 0;
        
        for (auto m : mp){
            if (m.second%2 == 0){
                palsize += m.second;
            }
            else{
                flag = 1;
                palsize += m.second - 1;
            }
        }
        
        if (flag == 1){
            return palsize + 1;
        }
        
        return palsize;
    }
};