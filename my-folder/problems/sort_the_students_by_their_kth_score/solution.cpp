class Solution {
public:
    // static int kth;
    // static bool compare(const vector<int> &a, const vector<int> &b){
    //     return a[0] > b[0];
    // }
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();
        
        for (int i=0; i<m; i++){
            int highVal = score[i][k];
            int highIndex = i;
            
            for (int j=i+1; j<m; j++){
                if (score[j][k] > highVal){
                    highVal = score[j][k];
                    highIndex = j;
                }
            }
            
            vector<int> temp = score[i];
            score[i] = score[highIndex];
            score[highIndex] = temp;
        }
        
        return score;
    }
};