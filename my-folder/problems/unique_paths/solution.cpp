class Solution {
    
private:
    int recursion(int i, int j, int m, int n, vector<vector<int>> &matrix){
        if (i==m-1 && j==n-1){
            matrix[i][j] = 1;
            return 1;
        }
        
        if (matrix[i][j] != 0){
            return matrix[i][j];
        }
        
        int count1 = 0, count2 = 0, count3 = 0;
        if (i == m-1){
            count1 = recursion(i, j+1, m, n, matrix);
        }
        else if (j == n-1){
            count2 = recursion(i+1, j, m, n, matrix);
        }
        else{
            count3 = recursion(i+1, j, m, n, matrix) + recursion(i, j+1, m, n, matrix);
        }
        
        matrix[i][j] = count1 + count2 + count3;
        return matrix[i][j];
    }
    
public:
    int uniquePaths(int m, int n) {
        int count = 0;
        
        vector<vector<int>> matrix;
        
//         for (int i=0; i<m; i++){
//             matrix[i][0] = 1;
//         }
        
//         for (int j=0; j<n; j++){
//             matrix[0][j] = 1;
//         }
        
//         for (int i=1; i<m; i++){
//             for (int j=1; j<n; j++){
//                 matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
//             }
//         }
        
        for (int i=0; i<m; i++){
            vector<int> temp;
            for (int j=0; j<n; j++){
                temp.push_back(0);
            }
            matrix.push_back(temp);
        }
        
        return recursion(0,0,m,n, matrix);
        
        // return matrix[m-1][n-1];
    }
};