class Solution {
public:
    int takeCharacters(string s, int k) {
        
        vector<int> abc(3,0);
        int n = s.size();
        
        for (char c: s){
            abc[c-'a']++;
        }
        
        if (abc[0] < k || abc[1] < k || abc[2] < k) return -1;
        
        int i = n - 1, j = n - 1;
        int ans = n;
        
        while(i >= 0){
            abc[s[i]-'a']--;
            
            while (abc[s[i]-'a'] < k){
                abc[s[j]-'a']++;
                j--;
            }
            
            ans = min(ans, n - (j-i+1) );
            i--;
        }
        
        return ans;
    }
};