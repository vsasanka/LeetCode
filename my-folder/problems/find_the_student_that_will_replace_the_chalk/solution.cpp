class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
//         unsigned long long sumTotal = accumulate(chalk.begin(), chalk.end(), 0);
        
//         k = k%sumTotal;
        int k1 = k;
        
        while(true){
            
            for (int i=0; i<chalk.size(); i++){
                if (k1 < chalk[i]) return i;

                k1 -= chalk[i];
            }
            
            k1 = k%(k - k1);
        }
        
        return 0;
    }
};