class Solution {
private:
    bool recursion(vector<vector<char>>& board, string word, int index, int row, \
                  int col, vector<vector<bool>> &visited){
        
        if (index==word.size()) return true;
        
        int m = board.size();
        int n = board[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col]){
            return false;
        }
        
        bool ans = false;
        
        visited[row][col] = true;
        
        if (word[index] == board[row][col]){
            ans = ans || recursion(board, word, index+1, row+1, col, visited);
            ans = ans || recursion(board, word, index+1, row-1, col, visited);
            ans = ans || recursion(board, word, index+1, row, col+1, visited);
            ans = ans || recursion(board, word, index+1, row, col-1, visited);
        }
        
        visited[row][col] = false;
        return ans;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (recursion(board, word, 0, i, j, visited)) return true;
            }
        }
        
        return false;
    }
};