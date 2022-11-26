class Solution {
public:
    int nthUglyNumber(int n) {
        
        int twop = 0, threep = 0, fivep = 0;
        
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(3);
        
        int maxSoFar;
        
        for(int i=3; i<n; i++){
            maxSoFar = ans[ans.size()-1];
            int a = ans[twop]*2;
            int b = ans[threep]*3;
            int c = ans[fivep]*5;
            
            while(a <= maxSoFar){
                twop++;
                a = ans[twop]*2;
            }
            
            while(b <= maxSoFar){
                threep++;
                b = ans[threep]*3;
            }
            
            while(c <= maxSoFar){
                fivep++;
                c = ans[fivep]*5;
            }
            
            ans.push_back(min(min(a,b),c));
        }
        
        return ans[n-1];
    }
};