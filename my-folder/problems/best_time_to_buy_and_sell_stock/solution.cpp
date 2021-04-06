class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minima = prices[0];
        int maxpro = 0;
        
        for (int i=0;i<prices.size();i++){
            if (prices[i]<minima){
                minima = prices[i];
            }
            else{
                int profit = prices[i] - minima;
                if (profit>maxpro){
                    maxpro = profit;
                }
            }
        }
        
        return maxpro;
    }
};