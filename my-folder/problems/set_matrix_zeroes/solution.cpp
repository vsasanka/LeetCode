class Solution {
public:
    void convertToZerosRow(vector<vector<int>>& matrix, int row){
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i=0; i<n; i++){
            matrix[row][i] = 0;
        }
    }

    void convertToZerosCol(vector<vector<int>>& matrix, int col){
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i=0; i<m; i++){
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows;
        vector<int> cols;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for (int i=0; i<rows.size(); i++){
            convertToZerosRow(matrix, rows[i]);
        }

        for (int i=0; i<cols.size(); i++){
            convertToZerosCol(matrix, cols[i]);
        }

        return ;
    }
};