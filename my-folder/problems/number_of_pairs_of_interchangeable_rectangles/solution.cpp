class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> ratios;
        long long pairs = 0;
        
        for (int i=0; i<rectangles.size(); i++){
            double ratio = (double)rectangles[i][0]/rectangles[i][1];
            ratios[ratio]++;
        }
        
        
        
        for (auto p: ratios){
            pairs += (long long)p.second*(p.second-1)/2;
        }
        
        return pairs;
    }
};