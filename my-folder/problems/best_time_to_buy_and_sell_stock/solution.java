class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int minSoFar = prices[0];

        for (int i=0; i<prices.length; i++){
            minSoFar = Math.min(minSoFar, prices[i]);
            profit = Math.max(profit, prices[i] - minSoFar);
        }

        return profit;
    }
}