class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morseMap[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> ans;
        
        for (int i=0; i<words.size(); i++){
            string morse = "";
            
            for (int j=0; j<words[i].size(); j++){
                morse.append(morseMap[words[i][j]-'a']);
            }
            
            ans.insert(morse);
        }
        
        return ans.size();
    }
};