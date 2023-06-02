class Solution {
public:
    void addValue(vector<vector<int>>& grid, int row, int col, queue<pair<int,int>> &q, vector<vector<bool>> &visited){
        int m = grid.size();
        int n = grid[0].size();

        if (row >= m || row < 0 || col >= n || col < 0 || visited[row][col] || grid[row][col] == 1) return ;

        visited[row][col] = true;
        // cout << row << " " << col << endl;
        q.push({row, col});
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return -1;

        int n = grid[0].size();

        if (grid[0][0] == 1) return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = true;
        int pathSize = 0;

        while (!q.empty()){
            int k = q.size();
            pathSize++;

            for (int i=0; i<k; i++){
                pair<int,int> p = q.front();

                q.pop();

                // cout << m-1 << " " << n - 1 << endl;
                if (p.first == m-1 && p.second == n-1) return pathSize;

                int r = p.first;
                int c = p.second;

                addValue(grid, r + 1, c + 1, q, visited);
                addValue(grid, r + 1, c, q, visited);
                addValue(grid, r + 1, c - 1, q, visited);
                addValue(grid, r, c + 1, q, visited);
                addValue(grid, r, c - 1, q, visited);
                addValue(grid, r - 1, c + 1, q, visited);
                addValue(grid, r - 1, c, q, visited);
                addValue(grid, r - 1, c - 1, q, visited);
            }
        }

        return -1;
    }
};