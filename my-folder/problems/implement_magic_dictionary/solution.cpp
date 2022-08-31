class MagicDictionary {
  
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for (string st: dictionary){
            MagicDictionary* node = this;
            
            for (char ch: st){
                ch -= 'a';
                if (!node->next[ch]) node->next[ch] = new MagicDictionary();
                node = node->next[ch];
            }
            
            node->isWord = true;
        }
    }
    
    
    
    bool search(string searchWord) {
        MagicDictionary* node = this;
        
        return searchOne(searchWord, node, 0);// recursion
    }
    
private:
    bool isWord = false;
    MagicDictionary* next[26] = {};
    
    bool searchOne(string searchWord, MagicDictionary* root, int tweaks){
        MagicDictionary* node = root;
        
        if (searchWord.size() == 0){
            if (tweaks == 0) return false;
            return node->isWord;
        }
        
        char ch = searchWord[0];
        ch -= 'a';
        
        bool value = false;
            
        for (int i=0; i<26; i++){

            if (node->next[i]){
                if (i == ch) 
                    value += searchOne(searchWord.substr(1,searchWord.size() - 1), node->next[i], tweaks);
                else if (tweaks == 0) 
                    value += searchOne(searchWord.substr(1,searchWord.size() - 1), node->next[i], tweaks+1);
            }
        }
        
        return value;
    }
        
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */