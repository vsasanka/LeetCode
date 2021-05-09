class Solution {
    
private:
    bool recursion(vector<vector<char>>& board, string word, int i, int j){
        
        if (word.size()==0){
            // cout << " 2 " << endl;
            return true;
        }
        
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[0]!=board[i][j]){
            // cout << " 1 "<<" "<< i << " " << j << endl;
            return false;
        }
        
        // cout << " 3 "<< endl;
        
        char temp = board[i][j];
        board[i][j] = '#';
        bool res=false;
        res = recursion(board,word.substr(1,word.size()-1), i+1,j);
        // cout << res << endl;
        res = res || recursion(board,word.substr(1,word.size()-1), i,j+1);
        // cout << res << endl;
        res = res || recursion(board,word.substr(1,word.size()-1), i-1,j);
        // cout << res << endl;
        res = res || recursion(board,word.substr(1,word.size()-1), i,j-1);
        // cout << res << endl;
        board[i][j] = temp;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool ans=false;
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                ans = recursion(board,word, i,j);
                if (ans){
                    return true;
                }
            }
        }
        
        return ans;
    }
};