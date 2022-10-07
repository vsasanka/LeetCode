class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        
        for (int i=0; i<arr.size(); i++){
            bitset<26> a;
            
            for (char c: arr[i]){
                a.set(c-'a');
            }
            // cout << 1 << endl;
            
            if (a.count() != arr[i].size()) continue;
            
            for (int j = dp.size() - 1; j>=0; j--){
                bitset b = dp[j];
                if ((a & b).any()) continue;
                
                // cout << 2 << endl;
                
                dp.push_back(a | b);
                res = max(res, (int)a.count() + (int)b.count());
            }
        }
        
        return res;
    }
};