class Solution {
    
private:
    int count(vector<vector<int>>&matrix, int mid){
        int n = matrix.size();
        int count = 0;
        int row = 0;
        int col = n-1;
        
        while(row<n && col>=0){
            if (matrix[row][col]<=mid){
                count += col+1;
                row++;
            }
            else{
                col--;
            }
        }
        
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int matrix_min = matrix[0][0];
        int matrix_max = matrix[n-1][n-1];
        int mid;
        
        while (matrix_min < matrix_max){
            mid = matrix_min + (matrix_max - matrix_min)/2;
            
            if (count(matrix, mid)<k){
                matrix_min = mid+1;
            }
            else{
                matrix_max = mid;
            }
        }
        
        return matrix_max;
    }
};