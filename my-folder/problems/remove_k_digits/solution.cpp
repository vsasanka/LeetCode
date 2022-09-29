class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if (k == 0){
            return num;
        }
        
        if (k >= num.size() || num.size() == 0){
            return "0";
        }
        
        stack<char> s;
        s.push(num[0]);
        
        for (int i=1; i<num.size(); i++){
            
            while(k > 0 && !s.empty() && num[i] < s.top()){
                k--;
                s.pop();
            }
            
            s.push(num[i]);
            
            if (s.size() == 1 && num[i] == '0'){
                s.pop();
            }
        }
        
        while(k && !s.empty()){
            k--;
            s.pop();
        }
        
        string res = "";
        
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        
        if (res.size() == 0) return "0";
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};