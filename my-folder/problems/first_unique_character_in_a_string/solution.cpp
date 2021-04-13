class Solution {
    
public:
    int firstUniqChar(string s) {
        map<char,int> mapping;
        map<char,int>::iterator itr;
        for (int i=0;i<s.size();i++){
            itr = mapping.find(s[i]);
            if (itr->first==s[i]){
                itr->second += 1;
            }
            else{
                mapping.insert(pair<char,int> (s[i],1));
            }
        }
        
        for (int i=0;i<s.size();i++){
            itr = mapping.find(s[i]);
            if (itr->second==1){
                return i;
            }
        }
        
        return -1;
    }
};