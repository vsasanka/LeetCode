class Solution {
    
private:
    bool revAndCompare(int num, int target){
        int dup = num;
        int newNum = 0;
        
        while (dup){
            newNum *= 10;
            newNum += dup%10;
            dup /= 10;
        }
        
        if (newNum + num == target) return true;
        return false;
    }
    
public:
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        
        int num1 = num/2;
        
        while (num1 < num){
            if (revAndCompare(num1, num)) return true;
            num1++;
        }
        
        return false;
    }
};