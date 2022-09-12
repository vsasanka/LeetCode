class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        
        sort(intervals.begin(), intervals.end());
        
        int ref = 0;
        for (int i=1; i<intervals.size(); i++){
            if (intervals[ref][1] > intervals[i][1]){
                count++;
                ref = i;
                continue;
            }
            
            if (intervals[ref][1] > intervals[i][0]){
                count++;
                continue;
            }
            
            ref = i;
        }
        
        return count;
    }
};

/*

[1 9] [3 14] [6 15] [8 20] [21 30] [31 40] [41 50] [42 53] [51 62] [55 67]

*/