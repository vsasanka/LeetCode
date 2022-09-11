class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> fre;
        int part = 0;
        
        for (int i=0; i<s.size(); i++){
            fre[s[i]]++;
            if (fre[s[i]] > 1){
                part++;
                fre.clear();
                fre[s[i]]++;
            }
        }
        
        return part+1;
    }
};