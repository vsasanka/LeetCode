class Solution {
public:
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> ints;
        vector<vector<int>> ans;

        for (auto c: intervals){
            ints.push_back({c[0],1});
            ints.push_back({c[1]+1,-1});
        }

        sort(ints.begin(), ints.end(), compare);

        int balance = 0;
        int leftTemp = -1;

        for (auto p: ints){
            balance += p.second;

            if (balance == 0){
                ans.push_back({leftTemp, p.first-1});
                leftTemp = -1;
            }

            if (balance > 0 && leftTemp == -1){
                leftTemp = p.first;
            }
        }

        return ans;
    }
};