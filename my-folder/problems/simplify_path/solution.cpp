class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        for (int i=0; i<path.size(); i++){
            if (path[i] == '/') continue;
            
            string s = path.substr(i);
            s = s.substr(0, s.find('/'));
            i = i + s.size();
            
            // cout << s << " ";
            
            if (s == ".") continue;
            
            if (s == "..") {
                if (!st.empty()) st.pop();
                continue;
            }
            
            st.push(s);
        }
        
        string ans;
        
        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }
        
        if (ans.size() == 0) return "/";
        
        return ans;
    }
};