class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mapping;
        
        mapping.insert(pair<char,int> ('I',1));
        mapping.insert(pair<char,int> ('V',5));
        mapping.insert(pair<char,int> ('X',10));
        mapping.insert(pair<char,int> ('L',50));
        mapping.insert(pair<char,int> ('C',100));
        mapping.insert(pair<char,int> ('D',500));
        mapping.insert(pair<char,int> ('M',1000));
        
        int sum = 0;
        int currval, prevval;
        map<char,int>::iterator itr;
        
        for (int i=s.size()-1;i>=0;i--){
            itr = mapping.find(s[i]);
            sum += itr->second;
            currval = itr->second;
            
            if ((i-1)>=0){
                itr = mapping.find(s[i-1]);
                prevval = itr->second;
                
                if (currval > prevval){
                    sum -= prevval;
                    i--;
                }
            }
        }
        
        return sum;
        
    }
};