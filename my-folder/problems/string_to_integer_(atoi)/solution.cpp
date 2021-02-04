class Solution {
private:
    int conversion(string num){
        int ans=0;
        int len=num.size();
        
        for(int i=0;i<len;i++){
            ans *=10;
            ans += (num[i]-'0');
        }
        
        return ans;
    }
public:
    int myAtoi(string s) {
        /*
        
        // remove any garbage (anything not in {' ','-','+',0-9 range})
        
        int i;
        int sign_flag=0;
        
        for (i=0;i<s.size();i++){
            if (s[i]==' ' || s[i]=='-' || s[i]=='+' || ( s[i]>='0' && s[i]<='9') ){
                if (s[i]=='-'){
                    sign_flag=1;
                    break;
                }
                if (s[i]==' '){
                    continue;
                }
                break;
            }
            else{
                return 0;
            }
        }
        
        
        
        */
        
        int i,j;
        int sign_flag=0;
        int number=0;
        int len=s.size();
        int nozero=0;
        string substring=""; // INT_MAX, INT_MIN
        string int_max = "2147483647";
        string int_min = "2147483648";
        
        for (i=0;i<len;i++){
            if (s[i]==' ' || s[i]=='-' || s[i]=='+' || ( s[i]>='0' && s[i]<='9') ){
                if (s[i]=='-'){
                    sign_flag=1;
                    i++;
                    break;
                }
                else if (s[i]=='+'){
                    i++;
                    break;
                }
                else if (s[i]==' '){
                    continue;
                }
                break;
            }
            else{
                return 0;
            }
        }
        
        for (j=i;j<len;j++){
            if (s[j]=='0' && nozero==0){
                continue;
            }
            else if(s[j]>='0' && s[j]<='9'){
                nozero=1;
                substring.push_back(s[j]);
            }
            else{
                break;
            }
        }
        
        if (sign_flag==1){
            if (substring.size()>int_min.size()){
                return -2147483648;
            }
            else if(substring.size()==int_min.size() && substring>=int_min){
                return -2147483648;
            }
            else{
                return (-1)*conversion(substring);
            }
        }
        else{
            if (substring.size()>int_max.size()){
                return 2147483647;
            }
            else if(substring.size()==int_max.size() && substring>=int_max){
                return 2147483647;
            }
            else{
                return conversion(substring);
            }
        }
        
        return 0;
    }
};