class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> matrix(m, vector<int>(n,0));
        
        matrix[0][0] = (text1[0] == text2[0]) ? 1 : 0;
        
        for (int i=1; i<m; i++){
            if (text1[i] == text2[0]){
                matrix[i][0] = 1;
            }
            else{
                matrix[i][0] = matrix[i-1][0];
            }
        }
        
        for (int i=1; i<n; i++){
            if (text1[0] == text2[i]){
                matrix[0][i] = 1;
            }
            else{
                matrix[0][i] = matrix[0][i-1];
            }
        }
        
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (text1[i] == text2[j]){
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                }
                else{
                    matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
                }
                // cout << matrix[i][j] << " ";
            }
            // cout << endl;
        }
        
        return matrix[m-1][n-1];
    }
};

/*
a b c d e f g h
d b c f h g a

*/