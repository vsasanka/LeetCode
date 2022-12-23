class Solution {
public:
    string word(string s, int index){
        int i = index;
        
        while (index < s.size() && 'a' <= s[index] && s[index] <= 'z'){
            index++;
        }
        return s.substr(i, index - i);
    }
    
    string decodeString(string s) {
        string curString;
        int curNum = 0;
        stack<int> stNums;
        stack<string> stStrings;
        
        for (char c: s){
            if (c == '['){
                stStrings.push(curString);
                stNums.push(curNum);
                curNum = 0;
                curString = "";
            }
            else if (c == ']'){
                string prevString = stStrings.top();
                stStrings.pop();
                int prevNum = stNums.top();
                stNums.pop();
                
                while (prevNum--){
                    prevString += curString;
                }
                
                curString = prevString;
            }
            else if (!isdigit(c)){
                curString += c;
            }
            else{
                curNum = curNum*10+ (c-'0');
            }
        }
        
        return curString;
    }
};