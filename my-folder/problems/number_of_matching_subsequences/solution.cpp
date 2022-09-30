class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indexes(26);
        int res = 0;
        
        for (int i=0; i<s.size(); i++){
            indexes[s[i] - 'a'].push_back(i);
        }
        
        for (int i=0; i<words.size(); i++){
            int x = -1;
            bool found = true;
            
            for (char c: words[i]){
                auto it = upper_bound(indexes[c - 'a'].begin(), indexes[c - 'a'].end(), x);
                if (it == indexes[c - 'a'].end()) found = false;
                else x = *it;
            }
            
            if (found) res++;
        }
        
        return res;
    }
};