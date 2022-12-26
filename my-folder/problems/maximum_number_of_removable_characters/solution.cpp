class Solution {
public:
    bool subsequenceCheck(string s1, string s2){
        int j = 0;
        int i = 0;
        
        while (i < s1.size() && j < s2.size()){
            if (s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        if (j == s2.size()) return true;
        
        return false;
    }
    
    void redactString(int index, vector<int>& removable, string &s){
        for (int i=0; i<=index; i++){
            s[removable[i]] = '.';
        }
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0;
        int r = removable.size()-1;
        
        while (l < r){
            int k = l + ((r-l)+1)/2;
            string s1 = s;
            redactString(k, removable, s1);
        
            if (subsequenceCheck(s1, p)){
                l = k;
            }
            else{
                r = k - 1;
            }
        }
        
        if (r == 0){
            string s1 = s;
            redactString(0, removable, s1);
            
            if (subsequenceCheck(s1, p)) return 1;
            else return 0;
        }
        
        return l+1;
    }
};