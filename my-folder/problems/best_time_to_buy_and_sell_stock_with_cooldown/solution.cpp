class Solution {
    
private:
    int dfs(int i, bool buying, map<pair<int,bool>,int> &dp, vector<int>&prices){
        if (i>=prices.size()){
            return 0;
        }
        
        if (dp.find({i,buying}) != dp.end()){
            return dp[{i,buying}];
        }
        
        if (buying){
            int buy = dfs(i+1, !buying, dp, prices) - prices[i];
            int cooldown = dfs(i+1, buying, dp, prices);
            dp[{i,buying}] = max(buy, cooldown);
        }
        else{
            int sell = dfs(i+2, !buying, dp, prices) + prices[i];
            int cooldown = dfs(i+1, buying, dp, prices);
            dp[{i,buying}] = max(sell, cooldown);
        }
        
        return dp[{i,buying}];
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        map<pair<int,bool>,int> dp;
        
        return dfs(0,true,dp, prices);
    }
};