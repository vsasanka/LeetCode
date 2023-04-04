class Solution {
public:
    int partitionString(string s) {
        int minPars = 1;
        int i=0, j=0;
        unordered_set<int> unset;

        while (j < s.size()){
            while (j < s.size() && unset.find(s[j]) == unset.end()){
                unset.insert(s[j]);
                j++;
            }

            if (j == s.size()) return minPars;

            unset.clear();
            unset.insert(s[j]);
            minPars++;
            j++;
        }

        return minPars;
    }
};