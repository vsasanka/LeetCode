class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<pair<int,int>> monSt;
        vector<unsigned long long> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        int MOD = 1000000000 + 7;

        unsigned long long ans = (unsigned long long)nums[0]*nums[0];

        for (int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
            // prefix[i] %= MOD;
        }

        for (int i=0; i<nums.size(); i++){
            int j = i;
            while (!monSt.empty() && monSt.top().first >= nums[i]){
                j = monSt.top().second;
                int topSt = monSt.top().first;
                if ((prefix[i-1] - prefix[j] + nums[j])*topSt > ans){
                    ans = (prefix[i-1] - prefix[j] + nums[j])*topSt;
                }
                
                monSt.pop();
            }

            monSt.push({nums[i], j});
            
            if (nums[i]*(prefix[i] - prefix[j] + nums[j]) > ans){
                ans = nums[i]*(prefix[i] - prefix[j] + nums[j]);
            }
        }

        int n = nums.size();

        while (monSt.empty() == false){
            // cout << monSt.top().first << " " << monSt.top().second << endl;
            int j = monSt.top().second;
            
            if ((monSt.top().first)*(prefix[n-1] - prefix[j] + nums[j]) > ans){
                ans = (monSt.top().first)*(prefix[n-1] - prefix[j] + nums[j]);
            }
            monSt.pop();
        }

        return ans%MOD;
    }
};