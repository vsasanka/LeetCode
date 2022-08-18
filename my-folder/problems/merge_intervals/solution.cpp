class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int left = intervals[0][0], right = intervals[0][1];
//         vector<vector<int>> ans;
        
//         for (int i=0; i<intervals.size(); i++){
//             left = min(intervals[i][0], left);
//             right = max(intervals[i][1], right);
            
//             if (intervals[i][0] == intervals[i][1]){
//                 vector<int> temp;
//                 temp.push_back(intervals[i][0]);
//                 temp.push_back(intervals[i][1]);
//                 ans.push_back(temp);
//             }
//         }
        
//         vector<int> project(right - left + 1, 0);
        
//         for (int i=0; i<intervals.size(); i++){
//             project[intervals[i][0] - left]++;
//             project[intervals[i][1] - left]--;
//         }
        
//         int check = 0;
        
//         int begin, end;
//         int flag = 0;
        
//         for (int i=0; i<project.size(); i++){
//             if (project[i] == 0){
//                 continue;
//             }
            
//             check += project[i];
            
//             if (check > 0 && flag == 0){
//                 begin = i+left;
//                 flag = 1;
//             }
//             else if (check == 0 && flag == 1){
//                 end = i+left;
//                 flag = 0;
//                 vector<int> temp;
//                 temp.push_back(begin);
//                 temp.push_back(end);
//                 ans.push_back(temp);
//             }
//         }
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){ return a[0] < b[0];});
        
        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];
        
        for (int i=1; i<intervals.size(); i++){
            if (right < intervals[i][0]){
                vector<int> temp;
                
                temp.push_back(left);
                temp.push_back(right);
                ans.push_back(temp);
                
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{
                right = max(intervals[i][1], right);
            }
        }
        
        vector<int> temp;
        temp.push_back(left);
        temp.push_back(right);
        ans.push_back(temp);
        
        return ans;
    }
};