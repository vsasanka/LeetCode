class Solution {
    
private:
    bool vowel(char c){
        if (c == 'a' 
           || c == 'e'
           || c == 'i'
           || c == 'o'
           || c == 'u'
           || c == 'A'
           || c == 'E'
           || c == 'I'
           || c == 'O'
           || c == 'U') return true;
        
        return false;
    }
    
public:
    bool halvesAreAlike(string s) {
        int countOfVowels1 = 0;
        int countOfVowels2 = 0;
        
        for (int i=0; i<s.size(); i++){
            if (i < s.size()/2){
                if (vowel(s[i])) countOfVowels1++;
            }
            else{
                if (vowel(s[i])) countOfVowels2++;
            }
        }
        
        if (countOfVowels1 == countOfVowels2){
            return true;
        }
        
        return false;
    }
};