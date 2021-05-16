class Solution {
    
private:
    long long int makeReverse(int x){
        long long int temp=0;
        
        while(x){
            temp *= 10;
            temp += (long long int)x%10;
            x /= 10;
        }
        
        return temp;
    }
    
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        long long int a = makeReverse(x);
        
        if (a==(1ll)*x){
            return true;
        }
        
        return false;
    }
};