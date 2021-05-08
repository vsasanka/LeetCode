class Solution {
    
    vector<string> result;
    
private:
    void brackets(int n, string str, int no_o, int no_c){
        if (str.size()==2*n){
            result.push_back(str);
            return ;
        }
        
        if (no_o<n){
            int no_o_dup = no_o+1;
            int no_c_dup = no_c+1;
            brackets(n,str+"(", no_o_dup,no_c_dup);
        }
        
        if (no_c>0){
            int no_c_dup = no_c-1;
            brackets(n,str+")", no_o,no_c_dup);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        
        brackets(n, "",0,0);
        
        return result;
    }
};