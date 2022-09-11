class Solution {
    
public:
    
    bool static compare(const pair<int,int>&a, const pair<int,int>&b){
        return a.first < b.first;
    }
    
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> A;
        
        for (int i=0; i<intervals.size(); i++){
            A.push_back({intervals[i][0],1});
            A.push_back({intervals[i][1]+1,-1});
        }
        
        sort(A.begin(), A.end());
        
        int res = 0, curr = 0;
        for (auto& p: A){
            // cout << p[0] << " " << p[1] << endl;
            curr += p[1];
            res = max(res, curr);
        }
        
        return res;
    }
};

/*

1 1 2   5 6
      3 5   8 10 10
*/