class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        stack<int> store;
        int row_size = matrix.size();
        
        for (int i=0;i<row_size/2;i++){
            // int row_size = matrix[0].size() - 2*i;
            // int row_limit = matrix.size()-i;
            
            for (int j=i;j<row_size-i;j++){
                store.push(matrix[i][j]);
            }
            
            for (int j=i;j<row_size-i;j++){
                matrix[i][row_size-1-j] = matrix[j][i];
            }
            
            for (int j=i;j<row_size-i;j++){
                matrix[j][i] = matrix[row_size-1-i][j];
            }
            
            for (int j=i;j<row_size-i;j++){
                matrix[row_size-1-i][j] = matrix[row_size-1-j][row_size-1-i];
            }
            
            for (int j=i;j<row_size-i;j++){
                matrix[row_size-1-j][row_size-1-i] = store.top();
                store.pop();
            }
        }
    }
};