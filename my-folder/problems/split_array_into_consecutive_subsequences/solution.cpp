class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> end, left;
        
        for (int i: nums){
            left[i]++;
        }
        
        for (int i: nums){
            if (left[i] == 0) continue;
            
            left[i]--;
            
            if (end[i - 1] > 0){
                end[i-1]--;
                end[i]++;
            }
            else if (left[i+1] > 0 && left[i+2] > 0){
                left[i+1]--;
                left[i+2]--;
                
                end[i+2]++;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};

/*

1 1 1 2 2 2 3 3 3 4 4 4 5 5 6 6 7 7

1 2 3 4 5 6 7
0 0 0 0 0 0 0

0 0 0 1 0 0 2
*/