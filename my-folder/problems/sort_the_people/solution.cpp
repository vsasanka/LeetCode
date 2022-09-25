class Solution {
private:
    bool static compare(const pair<string,int> &p1, const pair<string,int> &p2){
        return p1.second > p2.second;
    }
    
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> nh;
        
        for (int i=0; i<names.size(); i++){
            nh.push_back(make_pair(names[i], heights[i]));
        }
        
        sort(nh.begin(), nh.end(), compare);
        
        for (int i=0; i<names.size(); i++){
            names[i] = nh[i].first;
        }
        
        return names;
    }
};