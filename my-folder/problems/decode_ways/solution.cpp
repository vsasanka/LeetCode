class Solution {
    
public:
    int numDecodings(string s) {
        
        int ways = 0;
        vector<int> numPossible(s.size(), 0);
        
        if (s[0] == '0'){
            return 0;
        }
        
        if (s.size() == 1){
            return 1;
        }
        
        numPossible[0] = 1;
        
        if (s[1] == '0' && (s[0] == '1' || s[0] == '2')) numPossible[1] = 1;
        else if (s[0] == '1' || (s[0] == '2' && s[1]<='6')){
            numPossible[1] = 2;
        }
        else if (s[1] == '0'){
            return 0;
        }
        else{
            numPossible[1] = 1;
        }
        
        for (int i=2; i<s.size(); i++){
            
            if (s[i] == '0'){
                if (s[i-1] == '1' ||  s[i-1] == '2'){
                    numPossible[i] = numPossible[i-1] = numPossible[i-2];
                }
                else{
                    return 0;
                }
            }
            else if (s[i-1] == '1' ||  (s[i-1] == '2' && s[i]<='6')){
                numPossible[i] = numPossible[i-2] + numPossible[i-1];
            }
            else{
                numPossible[i] = numPossible[i-1];
            }
        }
        
        return numPossible[s.size() - 1];
    }
};

/*

1111106

1 11 1 10 6
11 11 10 6
1 1 11 10 6
11 1 1 10 6
1 1 1 1 10 6

206

1 1 1

216

1 2 3

*/