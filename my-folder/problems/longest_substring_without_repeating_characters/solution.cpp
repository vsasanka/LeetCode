class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> theSet;
        int n = s.size();
        int i,j;
        i = j = 0;
        int len = 0;
        int maxLen = 0;

        while (j < n && i<n){
            while (theSet.find(s[j]) != theSet.end()){
                theSet.erase(s[i]);
                i++;
            }

            theSet.insert(s[j]);

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }
};