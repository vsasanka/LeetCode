class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x^y;
        int dist = 0;
        
        while(num){
            dist += num%2;
            num /= 2;
        }
        
        return dist;
    }
};