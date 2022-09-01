class WordFilter {
private:
    bool isWord = false;
    unordered_map<char, WordFilter*> mp;
    int index;
    
    void insert(string word, int index){
        WordFilter* node = this;
        node->index = index;

        for (char ch: word){
            
            if (node->mp.find(ch) == node->mp.end()) {
                node->mp[ch] = new WordFilter();
            }

            node = node->mp[ch];
            node->index = index;
        }

        // cout << word << endl;
        
        node->isWord = true;
    }
    
public:
    WordFilter(){
        
    }
    
    WordFilter(vector<string>& words) {
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<words[i].size(); j++){
                // cout << words[i].substr(j,words[i].size()-j) << " ";
                insert(words[i].substr(j,words[i].size()-j) + '{' + words[i], i);
            }
        }
    }
    
    int f(string pref, string suff) {
        WordFilter* node = this;
        
        for (int i=0; i<suff.size(); i++){ // iterate suffix till { is found
            char ch = suff[i];
            
            if (node->mp.find(ch) == node->mp.end()) return -1;
            
            node = node->mp[ch];
            // if we encounter { then break;
            
        }
        
        // node = node->mp['{']
        if (node->mp.find('{') == node->mp.end()){
                return -1;
        }
        else{
            node = node->mp['{'];
        }
        
        for (int i=0; i<pref.size(); i++){// iterate accross prefix and find it
            char ch = pref[i];
            
            // once prefix found, return index of that node
            if (node->mp.find(ch) == node->mp.end()) return -1;
            
            node = node->mp[ch];
        }
        
        return node->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */