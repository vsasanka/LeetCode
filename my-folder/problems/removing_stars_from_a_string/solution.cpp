class Solution {
public:
    string removeStars(string s) {
        int starsCount = 0;
        string ans = "";

        for (int i=s.size() - 1; i>=0 ;i--){
            if (s[i] == '*'){
                starsCount++;
                s[i] = '-';
            }
            else if (starsCount > 0){
                starsCount--;
                s[i] = '-';
            }
        }

        for (int i=0; i<s.size(); i++){
            if (s[i] != '-') ans.push_back(s[i]);
        }

        return ans;
    }
};