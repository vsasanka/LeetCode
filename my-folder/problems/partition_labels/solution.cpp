class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> chars(26, make_pair(-1,-1));
        vector<int> ans;
        
        for (int i=0; i<s.size(); i++){
            if (chars[s[i] - 'a'].first == -1){
                // pair<int, int> p;
                // p.first = i;
                // p.second = i;
                chars[s[i] - 'a'] = make_pair(i,i);
            }
            else{
                chars[s[i] - 'a'].second = i;
            }
        }
        int left = chars[s[0]-'a'].first;
        int right = chars[s[0]- 'a'].second;
        
        chars[s[0]-'a'].first = -1;
        chars[s[0]-'a'].second = -1;
        // unordered_map<char, pair<int,int>>::iterator itr;
        
        // unordered_map<char, pair<int,int>> chars2(chars.end(), chars.begin());
        // reverse(chars.end(), chars.begin());
        
        for (int i=1; i<s.size(); i++){
            if (chars[s[i] - 'a'].first == -1){
                continue;
            }
            if (right > chars[s[i] - 'a'].first){
                right = max(right, chars[s[i] - 'a'].second);
                chars[s[i] - 'a'].first = -1;
                chars[s[i] - 'a'].second = -1;
            }
            else{
                ans.push_back(right - left + 1);
                left = chars[s[i] - 'a'].first;
                right = chars[s[i] - 'a'].second;
                chars[s[i] - 'a'].first = -1;
                chars[s[i] - 'a'].second = -1;
            }
        }
        
        ans.push_back(right - left + 1);

        return ans;
    }
};

/*

aba bcb aca def egd ehi jhk lij

a = 0 8
b = 1 5 left = 0, right = 8
c = 4 7 left = 0, right = 8

d = 9 14 
e = 10 15
f = 11 11
g = 13 13

a = 0 8
b = 1 5
c = 4 7
d = 9 14
e = 10 15
f = 11 11
g = 13 13


*/