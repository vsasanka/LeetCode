class Solution {
    
private:
    int convert2int(string rev){
        int ans=0;
        int len = rev.size();
        
        for (int i=0;i<len;i++){
            ans *= 10;
            ans += (rev[i]-'0');
        }
        
        return ans;
    }
    
public:
    int reverse(int x) {
        
        string int_max = "2147483647";
        string int_min = "2147483648";
        string rev="";
        
        int sign_flag = 0;
        
        if (x==0){
            return 0;
        }
        if (x == -2147483648){
            return 0;
        }
        
        if (x<0){
            sign_flag=1;
            x *= -1;
        }
        
        while(x){
            rev.push_back(x%10+'0');
            x /= 10;
        }
        
        // cout << rev << endl;
        
        if (sign_flag==1){
            if (rev.size()==int_min.size() && rev>int_min){
                return 0;
            }
            else{
                return (-1)*convert2int(rev);
            }
        }
        else{
            if (rev.size()==int_max.size() && rev>int_max){
                return 0;
            }
            else{
                return convert2int(rev);
            }
        }
    }
};