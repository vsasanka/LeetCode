class Solution {
    
private:
    int numHours(vector<int>& piles, int rate){
        int hours = 0;
        
        for (int i=0; i<piles.size(); i++){
            hours += piles[i]/rate;
            if (piles[i]%rate > 0) hours++;
        }
        
        return hours;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right){
            int mid = left + (right - left)/2;
            
            int hoursTaken = numHours(piles, mid);
            
            if (hoursTaken <= h){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};