class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int edge = 0;
        int maxe = 0; 
        
        int width;
        
        for (int i=0; i<wall[0].size(); i++){
            width += wall[0][i];
        }
        
        for (int i=0; i<wall.size(); i++){
            edge = 0;
            for (int j=0; j<wall[i].size(); j++){
                edge += wall[i][j];
                mp[edge]++;
                if (edge != width) maxe = max(maxe, mp[edge]);
            }
        }
        
        return wall.size() - maxe;
    }
};

/*

1 2 2 3 3 4
1 1 1 2 3 3
1 2 2 2 3 3
1 1 2 2 2 2
1 1 1 2 3 3
1 2 2 2 3 4


1 3 5 6
3 4 6
1 4 6
2 6
3 4 6
1 4 5 6



*/