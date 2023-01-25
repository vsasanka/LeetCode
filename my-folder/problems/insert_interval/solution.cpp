class Solution {
public:

    bool areIntervalsOverlapping(vector<int> &a, vector<int> &b){
        return min(a[1],b[1]) - max(a[0],b[0]) >= 0;
    }

    vector<int> mergeIntervals(vector<int> &a, vector<int> &b){
        return {min(a[0],b[0]), max(a[1],b[1])};
    }

    void addNewInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        int flag = 0;

        for (int i=0; i<intervals.size(); i++){
            if (newInterval[0] < intervals[i][0]){
                intervals.insert(intervals.begin()+i, newInterval);
                flag = 1;
                break;
            }
        }

        if (!flag){
            intervals.push_back(newInterval);
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        addNewInterval(intervals, newInterval);
        vector<vector<int>> ans;

        for (int i=0; i<intervals.size(); i++){
            vector<int> currInterval = {intervals[i][0],intervals[i][1]};

            while (i < intervals.size() && areIntervalsOverlapping(currInterval, intervals[i])){
                currInterval = mergeIntervals(currInterval, intervals[i]);
                i++;
            }

            i--;
            ans.push_back(currInterval);
        }

        return ans;
    }
};