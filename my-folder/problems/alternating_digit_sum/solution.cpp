class Solution {
public:
    int alternateDigitSum(int n) {
        bool plus = true;
        int ans = 0;
        int nums = 0;
        
        while(n){
            if (plus){
                ans += n%10;
            }
            else{
                ans -= n%10;
            }
            plus = !plus;
            n /= 10;
            nums++;
        }
        
        if (nums%2==0) return (-1)*ans;
        return ans;
    }
};