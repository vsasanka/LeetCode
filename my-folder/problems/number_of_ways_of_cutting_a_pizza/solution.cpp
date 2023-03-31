class Solution {
    
public:
    void applesCount(vector<vector<int>> &apples, vector<string>& pizza){
        int m = pizza.size();
        int n = pizza[0].size();

        if (pizza[m-1][n-1] == 'A') apples[m-1][n-1] = 1;
        
        for (int i=m-2; i>=0; i--){
            if (pizza[i][n-1] == 'A') apples[i][n-1] = 1 + apples[i+1][n-1];
            else apples[i][n-1] = apples[i+1][n-1];
        }

        for (int i=n-2; i>=0; i--){
            if (pizza[m-1][i] == 'A') apples[m-1][i] = 1 + apples[m-1][i+1];
            else apples[m-1][i] = apples[m-1][i+1];
        }

        for (int i=m-2; i>=0; i--){
            for (int j=n-2; j>=0; j--){
                if (pizza[i][j] == 'A') apples[i][j] = 1 + apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
                else apples[i][j] = apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
            }
        }
    }

    int recursion(vector<vector<int>> &apples, int k, int row, int col, vector<vector<vector<int>>> &dp){
        int m = apples.size();
        int n = apples[0].size();
        int MOD = 1000000007;

        if (row == m || col == n) return 0;
        if (apples[row][col] == 0) return 0;
        if (k == 0) return 1;
        if (dp[row][col][k] != -1) return dp[row][col][k];

        dp[row][col][k] = 0;

        for (int i=row+1; i<m; i++){
            if (apples[row][col] - apples[i][col] > 0) dp[row][col][k] = (dp[row][col][k] + recursion(apples, k-1, i, col, dp))%MOD;
        }

        for (int i=col+1; i<n; i++){
            if (apples[row][col] - apples[row][i] > 0) dp[row][col][k] = (dp[row][col][k] + recursion(apples, k-1, row, i, dp))%MOD;
        }
        return dp[row][col][k];
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        
        vector<vector<int>> apples(m, vector<int>(n,0));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));

        applesCount(apples, pizza);

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                cout << apples[i][j] << " ";
            }
            cout << endl;
        }
        
        return recursion(apples, k-1, 0, 0, dp);
    }
};


/*



*/