class TrieNode{
public:
    bool isWord;
    vector<TrieNode*> children;

    TrieNode(){
        isWord = false;
        children = vector<TrieNode*> (26,NULL);
    }
};

class Trie{

public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    TrieNode* getRoot() {return root;}
    
    void insert(string word){
        TrieNode* node = root;
        
        for (char ch: word){
            ch -= 'a';
            
            if (node->children[ch] == NULL) node->children[ch] = new TrieNode();
            
            node = node->children[ch];
        }
        
        node->isWord = true;
    }
    
};

class Solution {
    
private:
    void findW(vector<vector<char>>& board, TrieNode* root, set<string>& result, string word, int i, int j){
        if (i<0 || i>= board.size() || j < 0 || j>=board[0].size() || board[i][j] == ' ') return ;
        
        char ch = board[i][j];
        
        if (root->children[ch - 'a'] != NULL){
            
            word += ch;
            
            root = root->children[ch - 'a'];
            
            if (root->isWord) result.insert(word);
            
            // char temp = ch;
            board[i][j] = ' ';
            findW(board,root,result,word,i+1,j);
            findW(board,root,result,word,i-1,j);
            findW(board,root,result,word,i,j+1);
            findW(board,root,result,word,i,j-1);
            board[i][j] = ch;
            
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();
        
        
        for (string st: words){
            t->insert(st);
        }
        
        TrieNode* root = t->getRoot();
        
        set<string> result;
        
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                findW(board,root, result, "", i,j);
            }
        }
        
        vector<string> ans;
        
        for (string st: result){
            ans.push_back(st);
        }
        
        return ans;
    }
};