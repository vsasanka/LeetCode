class Solution {
    
private:
    bool validateBox(vector<vector<char>>& board, int row, int col, set<int>& sett){
        
        for (int i=row;i<row+3;i++){
            for (int j=col;j<col+3;j++){
                if (board[i][j]=='.'){
                    continue;
                }
                if (sett.find(board[i][j])!=sett.end()){
                    return false;
                }
                else{
                    sett.insert(board[i][j]);
                }
            }
        }
        sett.clear();
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        set<int> sett;
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]=='.'){
                    continue;
                }
                if (sett.find(board[i][j])!=sett.end()){
                    return false;
                }
                else{
                    sett.insert(board[i][j]);
                }
            }
            
            sett.clear();
        }
        
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[j][i]=='.'){
                    continue;
                }
                if (sett.find(board[j][i])!=sett.end()){
                    return false;
                }
                else{
                    sett.insert(board[j][i]);
                }
            }
            
            sett.clear();
        }
        
        bool ans=true;
        
        for (int i=0;i<9;i+=3){
            for (int j=0;j<9;j+=3){
                ans = ans && (validateBox(board, i,j, sett));
                if (ans==false){
                    return false;
                }
            }
        }
        
        return true;
    }
};