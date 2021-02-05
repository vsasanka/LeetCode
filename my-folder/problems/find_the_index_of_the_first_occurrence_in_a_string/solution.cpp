class Solution {
    
private:
    bool check(int index, string haystack, string needle){
        int i=0;
        int len = haystack.size();
        int len2 = needle.size();
        while( (index+i)<len && i<len2){
            if (haystack[i+index]!=needle[i]){
                return false;
            }
            i++;
        }
        
        if (i==len2){
            return true;
        }
        
        return false;
    }
    
public:
    int strStr(string haystack, string needle) {
        /*
        
        if (haystack.size()==0 || needle.size()==0){
            return 0;
        }
        
        for (iterate: haystack){
            if (check(index, haystack, needle)){
                return index;
            }
        }
        
        return -1;
        
        check(){}
        
        */
        
        int len1 = haystack.size();
        int len2 = needle.size();
        
        if (len2==0){
            return 0;
        }
        
        if (len1<len2){
            return -1;
        }
        
        for (int i=0;i<=len1-len2;i++){
            if (check(i, haystack, needle)){
                return i;
            }
        }
        
        return -1;
        
    }
};