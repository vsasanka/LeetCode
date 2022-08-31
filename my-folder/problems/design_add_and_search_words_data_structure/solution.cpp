class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        
        for (char ch: word){
            ch -= 'a';
            if (!node->next[ch]) {
                node->next[ch] = new WordDictionary();
            }
            node = node->next[ch];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) {
        WordDictionary* node = this;
        int flag = 0;
        const char* wordc = word.c_str();
        
        for (int k=0; k<word.size(); k++){
            char ch = word[k];
            
            if (ch != '.' && !node->next[ch - 'a']) return false;
            
            if (ch != '.') node = node->next[ch - 'a'];
            
            else if (ch == '.'){
                bool value = false;
                for (int i=0; i<26; i++){
                    
                    if (node->next[i])
                        value += search(word.substr(k+1,word.size()-k), node->next[i]);
                    
                    if (value) return true;
                }
                
                return value;
            }
            
        }
        
        return node->isWord;
    }
    
private:
    bool isWord = false;
    WordDictionary* next[26] = {};
    
    bool search(string word, WordDictionary* root) {
        
        // cout << word << " ";
        
        for (int k=0; word[k]; k++){
            char ch = word[k];
            // cout << ch << " ";
            if (ch != '.' && !root->next[ch - 'a']) return false;
            
            else if (ch == '.'){
                bool value = false;
                for (int i=0; i<26; i++){
                    
                    if (root->next[i]) 
                        value += search(word.substr(k+1,word.size()-k), root->next[i]);
                    
                    if (value) return true;
                }
                
                if (!value) return false;
            }
            
            root = root->next[ch - 'a'];
        }
        
        return root->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */