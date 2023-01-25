class Solution {
public:
    int numChars = 128;
    bool freqTableMatches(vector<int> &windowFreq, vector<int> &tFreq, int &tLetters){
        int uniqueMatches = 0;

        for (int i=0; i<numChars; i++){
            uniqueMatches += (tFreq[i] > 0 && tFreq[i] <= windowFreq[i]);
        }

        return tLetters == uniqueMatches;
    }

    string minWindow(string s, string t) {
        
        int j = 0;
        vector<int> tFreq(numChars, 0);
        vector<int> windowFreq(numChars, 0);
        int tLetters = 0;
        string ans = s;
        int ansFlag = 0;
        int ansLeft=0, ansRight=s.size() - 1, ansSize = s.size();

        if (t.size() > s.size()) return "";

        for (int i=0; i<t.size(); i++){
            tFreq[t[i]]++;
        }

        for (int i=0; i<tFreq.size(); i++){
            if (tFreq[i] > 0) tLetters++;
        }

        for (int i=0; i<s.size(); i++){
            
            while (j < s.size() && !freqTableMatches(windowFreq, tFreq, tLetters)){
                windowFreq[s[j]]++;
                j++;
            }

            if (freqTableMatches(windowFreq, tFreq, tLetters)){
                if (j - i < ansSize) {
                    ansSize = j - i;
                    ansLeft = i;
                    ansRight = j;
                }
                ansFlag = 1;
            }

            windowFreq[s[i]]--;
        }

        if (!ansFlag) return "";

        return s.substr(ansLeft, ansSize);
    }
};