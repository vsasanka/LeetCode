class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        
        for (int i=0; i<expression.size(); i++){
            char c = expression[i];
            if (expression[i] == '-' ||
               expression[i] == '+' ||
               expression[i] == '*'){
                vector<int> leftPart = diffWaysToCompute(expression.substr(0,i));
                vector<int> rightPart = diffWaysToCompute(expression.substr(i+1));
                
                for (auto l: leftPart){
                    for (auto r: rightPart){
                        int v = 0;
                        switch(c){
                            case '-':
                                v = l - r;
                                break;
                            case '+':
                                v = l + r;
                                break;
                            case '*':
                                v = l*r;
                                break;
                        }
                        res.push_back(v);
                    }
                }
            }
        }
        
        if (res.size() == 0) res.push_back(stoi(expression));
        return res;
    }
};