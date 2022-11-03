class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> likePairs;
        unordered_map<string, int> unlike;
        
        int palLen = 0;
        
        for (auto w: words){
            if (w[0] != w[1]){
                string st = w;
                reverse(st.begin(), st.end());
                if (unlike.find(st) != unlike.end()){
                    palLen += 4;
                    unlike[st]--;
                    if (unlike[st]  == 0) unlike.erase(st);
                }
                else{
                    unlike[w]++;
                }
            }
            else{
                likePairs[w]++;
                if (likePairs[w]%2 == 0){
                    palLen += 4;
                    likePairs[w] = 0;
                }
            }
        }
        
        for (auto p: likePairs){
            if (p.second%2 == 1){
                palLen += 2;
                break;
            }
        }
        
        return palLen;
    }
};


/*

["qo","fo","fq","qf","fo","ff","qq","qf","of","of","oo","of","of","qf","qf","of"]

qo - x
fo - of
fq - qf


*/