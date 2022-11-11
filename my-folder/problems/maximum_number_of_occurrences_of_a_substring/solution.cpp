class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        unordered_map<char,int> charSS;
        unordered_map<string,int> stringSS;
        int maxS = 0;
        
        for (int i=0; i<=s.size()-minSize; i++){
            
            int ucount = 0;
            
            for (int j=i; j<i+maxSize, j<s.size(); j++){
                
                int sz = j - i + 1;
                
                if (charSS.find(s[j]) == charSS.end()) ucount++;
                charSS[s[j]]++;
                
                // string tmp2 = s.substr(i, sz);
                
                if (ucount > maxLetters) break;
                
                // cout << tmp2 << " " << ucount << " " << maxLetters << endl;
                
                if (sz >= minSize){
                    string tmp = s.substr(i, sz);
                    // cout << tmp << endl;
                    stringSS[tmp]++;
                    
                    if (stringSS[tmp] > maxS){
                        maxS = stringSS[tmp];
                        // cout << tmp << " " << maxS << endl;
                    }
                }
            }
            
            charSS.clear();
        }
        
        return maxS;
    }
};