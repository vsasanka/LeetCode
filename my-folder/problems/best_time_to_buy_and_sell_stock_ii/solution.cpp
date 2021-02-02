class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // pseudo code
        /*
        
        low_temp,high_temp = A[0];
        
        for (iterate across array: i){
            if (i+1==A.size()){
            break;
            }
            if (A[i+1]>A[i]){
                // low_temp = same;
                high_temp = A[i+1];
            }
            else{
                low_temp = A[i+1];
                high_temp = A[i+1];
                profit_total += high_temp - low_temp;
            }
        }
        */
        
        int leng = prices.size();
        int temp_low = prices[0];
        int temp_high = prices[0];
        int max_profit=0;
        
        if(leng==1){
            return 0;
        }
        
        // 1,2
        
        for (int i=0;i<leng;i++){
            if( (i+1)==leng){
                max_profit += temp_high - temp_low;
            }
            else if(prices[i+1]<prices[i]){
                max_profit += temp_high - temp_low;
                temp_high= prices[i+1];
                temp_low = prices[i+1];
            }
            else if (prices[i+1]>=prices[i]){
                temp_high=prices[i+1];
            }
            
        }
        
        return max_profit;
    }
};