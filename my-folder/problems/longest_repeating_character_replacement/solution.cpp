class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26]={0};
        int maxlen = 1;
        int maxfreq = 1;
        int i,j;
        i = j = 0;
        
        for (int j=0; j<n; j++){
            maxfreq = max( maxfreq, ++freq[s[j]-'A']);
            
            while( j - i + 1 > k + maxfreq){
                freq[s[i]-'A']--;
                i++;
            }
            
            maxlen = max( maxlen, j - i + 1);
        }
        
        return maxlen;
    }
};