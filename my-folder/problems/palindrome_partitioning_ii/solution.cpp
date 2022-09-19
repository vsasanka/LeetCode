class Solution {
public:
    int minCut(string s) {
        vector<int> cut(s.size() + 1, 0);
        int n = s.size();
        
        for (int i = 0; i <= n; i++){
            cut[i] = i-1;
        }
        
        for (int i=0; i<n; i++){
            for (int j=0; i+j<n && i-j >= 0 && s[i-j] == s[i+j]; j++){
                cut[i+j+1] = min(cut[i+j+1], cut[i-j]+1);
            }
            
            for (int j=1; i+j<n && i-j+1 >= 0 && s[i-j+1] == s[i+j]; j++){
                cut[i+j+1] = min(cut[i+j+1], cut[i-j+1]+1);
            }
        }
        
        return cut[n];
    }
};