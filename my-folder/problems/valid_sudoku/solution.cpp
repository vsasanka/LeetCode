class Solution {
private:
    bool checkRow(vector<vector<char>>& board, int row){
        vector<int> mp(9, 0);
        
        for (int i=0; i<9; i++){
            char c = board[row][i];
            
            if (c != '.'){
                mp[c - '1']++;
                
                if (mp[c - '1'] > 1){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkColumn(vector<vector<char>>& board, int col){
        vector<int> mp(9, 0);
        
        for (int i=0; i<9; i++){
            char c = board[i][col];
            
            if (c != '.'){
                mp[c - '1']++;
                
                if (mp[c - '1'] > 1){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int row, int col){
        vector<int> mp(9, 0);
        
        for (int i=row; i<row+3; i++){
            for (int j=col; j<col+3; j++){
                char c = board[i][j];
            
                if (c != '.'){
                    mp[c - '1']++;

                    if (mp[c - '1'] > 1){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // validate row
        
        for (int i=0; i<9; i++){
            if (!checkRow(board, i)) return false;
        }
        
        // validate cols
        for (int i=0; i<9; i++){
            if (!checkColumn(board, i)) return false;
        }
        
        // validate boxes
        for (int i=0; i<9; i += 3){
            for (int j=0; j<9; j += 3){
                if (!checkBox(board, i, j)) return false;
            }
        }
        
        return true;
    }
};