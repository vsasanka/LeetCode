class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mappings;
        map<char,int> mappingt;
        map<char,int>::iterator itr;
        int i;
        char temp;
        map<char,int>::iterator itr2;
        
        for (i=0;i<s.size();i++){
            itr = mappings.find(s[i]);
            if (itr!=mappings.end()){
                itr->second += 1;
            }
            else{
                mappings.insert(pair<char,int> (s[i],1));
            }
        }
        
        for (i=0;i<t.size();i++){
            itr = mappingt.find(t[i]);
            if (itr!=mappingt.end()){
                itr->second += 1;
            }
            else{
                mappingt.insert(pair<char,int> (t[i],1));
            }
        }
        
        if (mappingt.size() != mappings.size()){
            return false;
        }
        
        for (itr2=mappingt.begin();itr2!=mappingt.end();itr2++){
            itr = mappings.find(itr2->first);
            if (itr==mappings.end() || (itr->second != itr2->second)){
                return false;
            }
        }
        
        return true;
    }
};