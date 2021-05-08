class Solution {
    vector<string> result;
    vector<vector<char>> combinations;
    
private:
    void createCombs(string digits, string substr, int index){
        
        // cout << "Substr: "<< substr << endl;
        if (index==digits.size()){
            result.push_back(substr);
            return ;
        }
        
        int indexnew = index+1;
        for (int i=0;i<combinations[digits[index]-'2'].size();i++){
            createCombs(digits, substr + combinations[digits[index]-'2'][i], indexnew);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.size()==0){
            return result;
        }
        
        combinations = 
        {{'a','b','c'},
         {'d','e','f'},
         {'g','h','i'},
         {'j','k','l'},
         {'m','n','o'},
         {'p','q','r','s'},
         {'t','u','v'},
         {'w','x','y','z'}};
        
        createCombs(digits, "", 0);
        
        // cout << (char)combinations[digits[0]-'2'][0] << endl;
        
        return result;
    }
};