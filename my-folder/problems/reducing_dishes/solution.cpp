class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int m = satisfaction.size();
        int ans = 0;

        for (int i=0; i<m; i++){
            int mul = 1;
            int sum = 0;

            for (int j = i; j<m; j++){
                sum += mul*satisfaction[j];
                mul++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};