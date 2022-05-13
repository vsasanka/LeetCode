class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int left = 0;
        int right = 0;
        
        for (int i=0; i<weights.size(); i++){
            // min, sum
            
            if (weights[i]>left){
                left = weights[i];
            }
            
            right += weights[i];
        }
        
        while(left<right){
            
            int tempw = 0;
            int daysr = 1;
            
            int mid = left + (right - left)/2;
            
            for (int i=0; i<weights.size(); i++){
                // #days
                if (tempw + weights[i] > mid){
                    daysr++;
                    tempw = 0;
                }
                
                tempw += weights[i];
            }
            
            // cout << mid << " " << daysr << endl;
            
            if (daysr<=days){
                right = mid;
            }
            else if (daysr > days){
                left = mid + 1;
            }
        }
        
        return right;
    }
};

/*
10
2

2 2 2 2 2
*/