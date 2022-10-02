class Solution {
public:
    
    int hg(int i, int j, vector<vector<int>>& grid){
        int sum = 0;
        for (int a = j; a<j+3; a++){
            sum += grid[i][a];
            // cout << grid[i][a] << " ";
        }
        
        for (int a = j; a<j+3; a++){
            sum += grid[i+2][a];
            // cout << grid[i+2][a] << " ";
        }
        
        sum += grid[i+1][j+1];
        
        return sum;
    }
    
    int maxSum(vector<vector<int>>& grid) {
        
        int maxv = 0;
        
        for (int i=0; i<grid.size()-2; i++){
            for (int j=0; j<grid[0].size()-2; j++){
                maxv = max(maxv, hg(i,j,grid));
            }
        }
        
        // maxv = hg(0,0,grid);
        
        return maxv;
    }
};