class Solution {
    int xE;
    int yE;
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       
        xE = entrance[0];
        yE = entrance[1];
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(maze.size(), \
                                     vector<bool>(maze[0].size(), false));
        
        int m = maze.size();
        int n = maze[0].size();
        int steps = 0;
        
        // cout << m << " " << n << endl;
        
        q.push({xE,yE});
        visited[xE][yE] = true;
        
        while(!q.empty()){
            int qs = q.size();
            
            // cout << 1 << endl;
            
            for (int i=0; i<qs; i++){
                auto [x,y] = q.front();
                q.pop();
                
                // cout << x << " " << y << endl;
                
                if (x == 0 || x == m-1 || y == 0 || y == n-1){
                    if (steps != 0 && maze[x][y] == '.') return steps;
                }
                
                // cout << 4 << endl;
                
                if (maze[x][y] == '.'){
                    if (x + 1 < m && visited[x+1][y] == false){
                        q.push({x+1,y});
                        visited[x+1][y] = true;
                    }
                    // cout << 5 << endl;
                    if (x-1 >= 0 && visited[x-1][y] == false){
                        q.push({x-1,y});
                        visited[x-1][y] = true;
                    }
                    // cout << 6 << endl;
                    if (y-1 >= 0 && visited[x][y-1] == false){
                        q.push({x,y-1});
                        visited[x][y-1] = true;
                    }
                    // cout << y << " " << n << endl;
                    // cout << visited[x][y+1] << endl;
                    if (y + 1 < n && visited[x][y+1] == false){
                        // cout << 7 << endl;
                        q.push({x,y+1});
                        visited[x][y+1] = true;
                    }
                }
            }
            // cout << 2 << endl;
            steps++;
        }
        
        return -1;
    }
};