class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<int> uniqueElems(s.size(), 0);
        vector<pair<int,int>> firstLast(26,{INT_MAX,-1});
        unordered_map<char,int> mp;
        
        int uniqueElements = 0;
        
        for (int i=0; i<s.size(); i++){
            firstLast[s[i]-'a'].first = min(firstLast[s[i]-'a'].first, i);
            firstLast[s[i]-'a'].second = i;
        }
        
        int ans = 0;
        
        for (int i=0; i<26; i++){
            if (firstLast[i].first < firstLast[i].second)
                ans += unordered_set<char>(s.begin() + firstLast[i].first + 1, s.begin() + firstLast[i].second).size();
        }
        
        return ans;
    }
};