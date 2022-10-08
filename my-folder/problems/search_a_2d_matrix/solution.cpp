class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n - 1;
        int mid;
        
        while (left < right){
            mid = left + (right - left)/2;
            
            int row = mid/n;
            int col = mid%n;
            
            if (matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        
        int row = left/n;
        int col = left%n;
        
        if (matrix[row][col] == target){
            return true;
        }
        
        return false;
    }
};