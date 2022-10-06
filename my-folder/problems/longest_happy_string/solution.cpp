class Solution {
    
private:
    string longestDiverseString(int a, int b, int c, char aa, char bb, char cc){
        if (a < b){
            return longestDiverseString(b,a,c,bb,aa,cc);
        }
        if (b < c){
            return longestDiverseString(a,c,b,aa,cc,bb);
        }
        if (b == 0){
            return string(min(2,a),aa);
        }
        
        string apart = string(min(2,a),aa);
        string bpart = "";
        a -= min(2,a);
        
        if (a >= b){
            bpart += bb;
            b--;
        }
        
        return apart + bpart + longestDiverseString(a,b,c,aa,bb,cc);
    }
    
public:
    string longestDiverseString(int a, int b, int c) {
        return longestDiverseString(a,b,c,'a','b','c');
    }
};