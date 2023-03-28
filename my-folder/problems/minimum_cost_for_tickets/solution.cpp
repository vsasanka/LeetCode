class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(days.begin(), days.end());
        vector<int> dp(366, 0);

        for (int i=1; i<=365; i++){
            if (s.find(i) == s.end()){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = dp[i-1] + min(costs[0],min(costs[1],costs[2]));

                if (i-7 < 0){
                    dp[i] = min(dp[i], min(costs[1],costs[2]));
                }
                else{
                    dp[i] = min(dp[i], dp[i-7] + min(costs[1],costs[2]));
                }

                if (i-30 < 0){
                    dp[i] = min(dp[i], costs[2]);
                }
                else{
                    dp[i] = min(dp[i], dp[i-30] + costs[2]);
                }
            }
        }

        return dp[365];
    }
};