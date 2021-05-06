class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mapping;
        int max_count=0;
        map<char,int>::iterator itr;
        
        for (int i=0,j=0;j<s.size();j++){
            itr = mapping.find(s[j]);
            if (itr!=mapping.end()){
                // cout << i << " update" << " ";
                i = max(i, itr->second+1);
                itr->second = j;
            }
            else{
                mapping.insert(pair<char,int>(s[j],j));
            }
            // cout << i << " " << j << " ";
            max_count = max(max_count , j-i+1);
            // cout << max_count << endl;
        }
        return max_count;
    }
};

// a b c d a e f g h
/*
a 0
    b 1
    c 2
    d 3
    
    
    b 1
    c 2
    d 3
    a 4
    e 
    */