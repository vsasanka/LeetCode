class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long int> nums;
        string s = "";
        
        for (int i=0; i<tokens.size(); i++){
            if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/"){
                long int first = nums.top();
                nums.pop();
                long int second = nums.top();
                nums.pop();
                
                if (tokens[i] == "+"){
                    nums.push(first + second);
                }
                else if (tokens[i] == "-"){
                    nums.push(second - first);
                }
                else if (tokens[i] == "*"){
                    nums.push(second*first);
                }
                else if (tokens[i] == "/"){
                    nums.push(second/first);
                }
            }
            else{
                long int num = (long) stoi(tokens[i]);
                nums.push(num);
            }
        }
        
        return (int) nums.top();
    }
};