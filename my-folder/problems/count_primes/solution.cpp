class Solution {
    
private:
    bool isPrime(int m){
        int sqrtm = sqrt(m);
        
        for (int i=3;i<=sqrtm;i+=2){
            if (m%i==0){
                return false;
            }
        }
        
        return true;
    }
    
public:
    int countPrimes(int n) {
        if (n==0 || n==1 || n==2){
            return 0;
        }
        
        int count = 1;
        
        for (int i=3;i<n;i+=2){
            if (isPrime(i)){
                count++;
            }
        }
        
        return count;
    }
};