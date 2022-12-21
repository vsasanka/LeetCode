class Solution {
public:
    int minSwaps(string s) {
        int balance_left = 0;
        int balance_right = 0;
        
        int l = 0, r = s.size() - 1;
        
        int swaps = 0;
        
        while (l < r){
            
            while (balance_left >= 0 && l < r){
                balance_left += s[l] == '[' ? 1 : -1;
                if (balance_left >= 0) l++;
            }
            
            while (balance_right >= 0 && l < r){
                balance_right += s[r] == ']' ? 1 : -1;
                if (balance_right >= 0) r--;
            }
            
            if (l < r){
                s[l] = '[';
                s[r] = ']';
                swaps++;
                l++;
                r--;
                balance_left += 2;
                balance_right += 2;
            }
        }
        
        return swaps;
    }
};