class Solution {
public:
    string countAndSay(int n) {
        
        string ans="";
        ans="1";
        
        while(n-1>0){
            int local_freq = 1;
            int len = ans.size();
            string ans_temp = "";
            
            for (int i=0;i<len;i++){
                if ( (i+1)==len || ans[i+1]!=ans[i]){
                    ans_temp.push_back(local_freq+'0');
                    ans_temp.push_back(ans[i]);
                    local_freq=1;
                }
                else{
                    local_freq++;
                }
            }
            
            ans = ans_temp;
            
            n--;
        }
        
        return ans;
    }
};