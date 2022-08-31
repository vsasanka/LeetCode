struct Trie{
    bool isRoot;
    Trie* next[26];
    Trie(){
        isRoot = false;
        memset(next,NULL,sizeof(next));
    }
};

class Solution {
public:
    void insert(string word, Trie* root){
        Trie* node = root;
        
        // cout << word << " ";
        
        for (char ch: word){
            if (node->isRoot) return ;
            
            if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Trie;
            node = node->next[ch - 'a'];
            // cout << ch << endl;
        }
        
        
        node->isRoot = true;
    }
    
    string prefix(string word, Trie* root){
        Trie* node = root;
        
        // string pref = "";
        // cout << word << endl;
        
        for (int i=0; i < word.size(); i++){
            char ch = word[i];
            
            // cout << ch << endl;
            
            if (node->isRoot) {
                // cout << 2 << endl;
                return word.substr(0,i);
            }
            
            if (!node->next[ch - 'a']) {
                // cout << 1 << endl;
                return word;
            }
            
            // pref += ch;
            // cout << 3 << endl;
            node = node->next[ch - 'a'];
        }
        
        // cout << 4 << endl;
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* t = new Trie;
        string ans = "";

        for (auto s: dictionary){
            insert(s,t);
        }

        int i,j;

        i = 0;
        j = 1;

        while (j < sentence.size()){
            
            // cout << i << " " << j << endl;
            while (sentence[j] != ' ' && j!= sentence.size()){
                j++;
                // cout << i << " " << j << endl;
            }

            string word = sentence.substr(i, j-i);
            ans += prefix(word,t);
            
            if (j == sentence.size()){
                break;
            }
            
            ans += " ";

            while (j!= sentence.size() && sentence[j]==' '){
                j++;
            }
            i = j;
            
        }

        return ans;
    }
    
};

