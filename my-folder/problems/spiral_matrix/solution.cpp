class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // for (i variable 0 to rows/2)
        // {
        
        // traverse line 1
        
        // traverse column last
        
        // traverse row last (reverse)
        
        // traverse column 1 reverse (except first element)
        
        // }
        vector<int> ans;
        int limit = min(matrix.size()+1, matrix[0].size()+1)/2;
        
        for (int k=0; k < limit; k++){
            
            for (int i=k; i<matrix[0].size() - k; i++){
                // cout << matrix[k][i] << " ";
                ans.push_back(matrix[k][i]);
            }
            
            for (int i=k+1; i<matrix.size() - k; i++){
                // cout << matrix[i][matrix[0].size() - k - 1] << " ";
                ans.push_back(matrix[i][matrix[0].size() - k - 1]);
            }
            
            if (k != matrix[0].size() - k - 1 && k != matrix.size() - k - 1)
            {
                for (int i=matrix[0].size() - 1 - k -1; i>=k; i--){
                    // cout << matrix[matrix.size() - 1 - k][i] << " ";
                    ans.push_back(matrix[matrix.size() - 1 - k][i]);
                }
                
                for (int i=matrix.size() - 1 - k - 1; i>=k+1; i--){
                    // cout << matrix[i][k] << " ";
                    ans.push_back(matrix[i][k]);
                }
            }
            
//             if (k != matrix.size() - k - 1){
//                 for (int i=matrix.size() - 1 - k - 1; i>=k+1; i--){
//                     // cout << matrix[i][k] << " ";
//                     ans.push_back(matrix[i][k]);
//                 }
//             }
            
        }
        
        return ans;
    }
};