class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losers;
        vector<vector<int>> ans(2);
        
        for (auto vec: matches){
            losers[vec[1]]++;
        }
        
        vector<int> temp;
        for (auto l: losers){
            if (l.second == 1){
                temp.push_back(l.first);
            }
        }
        sort(temp.begin(), temp.end());
        ans[1] = temp;
        
        set<int> temp2;
        
        for (auto vec: matches){
            if (losers.find(vec[0]) == losers.end()){
                temp2.insert(vec[0]);
            }
        }
        
        vector<int> temp3(temp2.begin(), temp2.end());
        sort(temp3.begin(), temp3.end());
        
        ans[0] = temp3;
        
        return ans;
    }
};