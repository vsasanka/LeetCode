class Solution {
public:
    void createV(string &s, int index, int &numRows, vector<string> &ans){
        int n = s.size();
        
        for (int i=0; i<numRows; i++){
            if (index < n) ans[i].push_back(s[index++]);
        }

        for (int i=numRows-2; i>0; i--){
            if (index < n) ans[i].push_back(s[index++]);
        }
    }

    string convert(string s, int numRows) {
        vector<string> ans(numRows, "");
        string finalString = "";

        if (numRows == 1) return s;

        for (int i=0; i<s.size(); i += 2*numRows - 2){
            createV(s, i, numRows, ans);
        }

        for (auto s: ans){
            finalString.append(s);
        }

        return finalString;
    }
};

/*

0
1, 2n - 2 - 1
2, 2n - 2 - 2
3


*/