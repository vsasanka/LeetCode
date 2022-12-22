class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string sNew = s + s.substr(0,n-1);
        int flag = 0;
        string b1;
        string b2;
        
        for (int i=0; i<sNew.size(); i++){
            b1 += i % 2 ? '0' : '1';
            b2 += i % 2 ? '1' : '0';
        }
        
        int l = 0;
        int diff1 = 0;
        int diff2 = 0;
        int diffMin = INT_MAX;
        
        for (int r = 0; r<sNew.size(); r++){
            
            if (sNew[r] != b1[r]) diff1++;
            if (sNew[r] != b2[r]) diff2++;
            
            if (r - l + 1 == n){
                diffMin = min(diffMin,min(diff1,diff2));
                
                if (sNew[l] != b1[l]) diff1--;
                if (sNew[l] != b2[l]) diff2--;
                l++;
            }
        }
        
        return diffMin;
    }
};

/*

1100000

1000001

11100000

11000001

10000011


0011100

1100001
*/