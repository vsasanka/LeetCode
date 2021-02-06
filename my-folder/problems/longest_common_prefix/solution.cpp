class Solution {
private:
    string commonPrefix(string& str1, string& str2){
        string prefix="";
        
        // int len1 = str1.size();
        // int len2 = str2.size();
        int i=0;
        
        while(i<str1.size() && i<str2.size()){
            if (str1[i]==str2[i]){
                prefix.push_back(str1[i]);
            }
            else{
                break;
            }
            i++;
        }
        
        return prefix;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()){
            return "";
        }
        
        int len = strs.size();
        string ans=strs[0];
        
        for (int i=1;i<len;i++){
            ans = commonPrefix(strs[i],ans);
            if (ans==""){
                return "";
            }
        }
        
        return ans;
    }
};