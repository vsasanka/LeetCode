class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        dp[days[0]] = costs[0];
        
        for (int i=1; i<days.size(); i++){
            dp[days[i]] = costs[0] + dp[days[i-1]];
        }
        
        dp[0] = 0;
        int lastDay = 1;
        int today = 1;
        
        for (int i=0; i<days.size(); i++){
            today = days[i];
            
            for (int j=lastDay+1; j<today; j++){
                dp[j] = dp[j-1];
            }
            
            if (today - 1 >= 0){
                dp[today] = dp[today - 1] + min(min(costs[0],costs[1]), costs[2]);
            }
            
            if (today - 7 >= 0){
                dp[today] = min(dp[today - 7] + min(costs[1], costs[2]), dp[today]);
            }
            else{
                dp[today] = min(min(costs[1], costs[2]), dp[today]);
            }
            
            if (today - 30 >= 0){
                dp[today] = min(dp[today - 30] + costs[2], dp[today]);
            }
            else{
                dp[today] = min(costs[2], dp[today]);
            }
            
            lastDay = today;
        }
        
        // for (int i=0; i<=days[days.size()-1]; i++){
        //     cout << dp[i] << " ";
        // }
        
        return dp[days[days.size()-1]];
    }
};