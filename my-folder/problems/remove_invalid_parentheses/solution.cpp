class Solution {
    
private:
    void reset(set<string> &validExps){
        validExps.clear();
    }
    
    void recursion(set<string> &validExps, string &s, int leftb, int rightb, int numRem, int &minRem, string &expression, int index){
        if (index == s.size()){
            if (leftb > rightb || leftb < rightb){
                return ;
            }
            
            if (numRem < minRem){
                reset(validExps);
                minRem = numRem;
                validExps.insert(expression);
                return ;
            }
            
            if (numRem == minRem){
                validExps.insert(expression);
                return ;
            }
            
            return ;
        }
        
        int i = index;
        int len = expression.size();
        
        if (s[i] != '(' && s[i] != ')'){
            expression += s[i];
            // cout << s[i];
            recursion(validExps, s, leftb, rightb, numRem, minRem, expression, index + 1);
            expression.erase(len);
            // cout << expression << " ";
        }
        else{
            recursion(validExps, s, leftb, rightb, numRem + 1, minRem, expression, index + 1);
            expression += s[i];


            if (s[i] == '('){
                recursion(validExps, s, leftb + 1, rightb, numRem, minRem, expression, index+1);
            }
            else if (leftb > rightb){
                recursion(validExps, s, leftb, rightb + 1, numRem, minRem, expression, index+1);
            }
            // cout << 1 << endl;
            expression.erase(len);
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> validExps;
        string expression = "";
        int minLen = INT_MAX;
        
        recursion(validExps,s,0,0,0,minLen,expression,0);
        
        vector<string> ans;
        for (auto s: validExps){
            ans.push_back(s);
        }
        
        return ans;
    }
};