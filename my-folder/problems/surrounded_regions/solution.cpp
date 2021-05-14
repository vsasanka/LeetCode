class Solution {
public:
    void dfs(vector<vector<char>>& board, int i,int j){
        board[i][j]='1';
        
        if ( (i-1)>=0 && board[i-1][j]=='O'){
            dfs(board,i-1,j);
        }
        
        if ( (j-1)>=0 && board[i][j-1]=='O'){
            dfs(board,i,j-1);
        }
        
        if ( (i+1)<board.size() && board[i+1][j]=='O'){
            dfs(board,i+1,j);
        }
        
        if ( (j+1)<board[0].size() && board[i][j+1]=='O'){
            dfs(board,i,j+1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        int row = board.size(), col = board[0].size();
        
        for (int i = 0 ;i<row;i++){
            if (board[i][0]=='O'){
                dfs(board,i,0);
            }
            
            if (col>1 && board[i][col-1]=='O'){
                dfs(board,i,col-1);
            }
        }
        
        for (int j=1;j<col-1;j++){
            if (board[0][j]=='O') dfs(board,0,j);
            
            if (row>1 && board[row-1][j]=='O'){
                dfs(board,row-1,j);
            }
        }
        
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='1') board[i][j]='O';
            }
        }
    }
};