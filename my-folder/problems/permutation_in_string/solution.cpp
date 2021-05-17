class Solution {
    
private:
    bool sameFreq(vector<int> &freqone, vector<int> &freqtwo){
        for (int i=0;i<26;i++){
            if (freqone[i] != freqtwo[i]) return false;
        }
        
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqone(26,0);
        vector<int> freqtwo(26,0);
        int i,j;
        i = j = 0;
        
        int k = s1.size();
        int n = s2.size();
        
        for (int m=0;m<s1.size();m++){
            freqone[s1[m] - 'a']++;
        }
        
        while(j < n){
            freqtwo[s2[j]-'a']++;
            
            if (j-i+1 == k){
                
                if (sameFreq(freqone, freqtwo)){
                    return true;
                }
                freqtwo[s2[i]-'a']--;
                i++;
            }
            j++;
        }
        
        return false;
    }
};