class Solution {
public:
    bool compare(vector<bool> &a , vector<bool> &b){
        for (int i=0; i<26; i++){
            if (a[i] && b[i]){
                
                // cout << i << endl;
                return false;
            }
        }
        
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> freqs(words.size(), vector<bool>(26,false));
        
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<words[i].size(); j++){
                // cout << words[i][j] - 'a' << " ";
                freqs[i][words[i][j] - 'a'] = true;
            }
            
//             for (int j=0; j<26; j++){
//                 cout << freqs[i][j] << " ";
//             }
//             cout << endl;
        }
        
        int maxp = 0;
        int prod;
        
        for (int i=0; i<words.size(); i++){
            for (int j=i+1; j<words.size(); j++){
                // cout << words[i] << " " << words[j] << endl;
                if (compare(freqs[i], freqs[j])){
                    // cout << 1 << endl;
                    prod = words[i].size() * words[j].size();
                    maxp = max(maxp, prod);
                }
            }
        }
        
        return maxp;
    }
};