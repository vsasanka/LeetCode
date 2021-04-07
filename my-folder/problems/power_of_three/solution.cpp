class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==0){
            return false;
        }
        
        double logn3 = log(n)/log(3);
        
        for (int i=0;i<logn3;i++){
            if (n%3!=0){
                return false;
            }
            n/= 3;
        }
        
        if (1==n){
            return true;
        }
        else{
            return false;
        }
    }
};