class Solution {
    
private:
    void zerofyrow(vector<vector<int>>& matrix, int row){
        
        for (int i=0;i<matrix[0].size();i++){
            matrix[row][i]=0;
        }
    }
    
private:
    void zerofycol(vector<vector<int>>& matrix, int col){
        for (int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
        }
    }
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row_flag=0;
        int col_flag = 0;
        
        for (int i=0;i<matrix[0].size();i++){
            if (matrix[0][i]==0){
                row_flag = 1;
                break;
            }
        }
        
        for (int i=0;i<matrix.size();i++){
            if (matrix[i][0]==0){
                col_flag = 1;
                break;
            }
        }
        
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    // cout << i << " " << j << endl;
                    matrix[0][j]=0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        
        
        // cout << " ... " << endl;
        for (int i=1;i<matrix[0].size();i++){
            // cout << zeros[i].first << " " << zeros[i].second << endl;
            if (matrix[0][i]==0){
                zerofycol(matrix, i);
            }
        }
        
        for (int i=1;i<matrix.size();i++){
            // cout << zeros[i].first << " " << zeros[i].second << endl;
            if (matrix[i][0]==0){
                zerofyrow(matrix, i);
            }
        }
        
        if (row_flag){
            zerofyrow(matrix, 0);
        }
        if (col_flag){
            zerofycol(matrix, 0);
        }
    }
};