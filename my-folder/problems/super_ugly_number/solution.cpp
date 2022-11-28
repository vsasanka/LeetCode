class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> ans;
        vector<int> indeces(primes.size(), 0);
        ans.push_back(1);
        
        for (int i=1; i<n; i++){
            long toCompare = ans[ans.size() - 1];
            int ansSize = ans.size();
            long toPush = INT_MAX;
            
            for (int j=0; j<primes.size(); j++){
                int pnum = primes[j];
                
                while (ans[indeces[j]]*pnum <= toCompare){
                    indeces[j]++;
                }
                toPush = min(toPush, ans[indeces[j]]*pnum);
            }
            
            ans.push_back((long)toPush);
        }
        
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        
        return (int)ans[ans.size() - 1];
    }
};