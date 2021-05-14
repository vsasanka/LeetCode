class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rottenOranges;
        int fresh=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==2){
                    rottenOranges.push(make_pair(i,j));
                }
                if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        // cout << fresh << endl;
        // cout << rottenOranges.size() << endl;
        
        int minutes = 0;
        
        while(!rottenOranges.empty() && fresh>0){
            int n = rottenOranges.size();
            for (int i=0;i<n;i++){
                int col,row;
                
                if (fresh==0) break;
                
                pair<int,int> p = rottenOranges.front();
                rottenOranges.pop();
                row = p.first;
                col = p.second;
                
                // cout << row << " " << col << endl;
                
                if (row + 1 < grid.size() && grid[row+1][col] == 1){
                    fresh--;
                    grid[row+1][col] = 2;
                    rottenOranges.push(make_pair(row+1,col));
                }
                
                if (col+1 < grid[0].size() && grid[row][col+1] == 1){
                    fresh--;
                    grid[row][col+1] = 2;
                    rottenOranges.push(make_pair(row,col+1));
                }
                
                if (row-1 >= 0 && grid[row-1][col]==1){
                    fresh--;
                    grid[row-1][col] = 2;
                    rottenOranges.push(make_pair(row-1,col));
                }
                
                if (col-1 >= 0 && grid[row][col-1]==1){
                    fresh--;
                    grid[row][col-1] = 2;
                    rottenOranges.push(make_pair(row,col-1));
                }
            }
            
            // cout << rottenOranges.size() << endl;
            
            minutes++;
        }
        
        if (fresh!=0){
            return -1;
        }
        
        return minutes;
    }
};