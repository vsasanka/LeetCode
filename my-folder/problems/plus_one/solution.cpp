class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
        
        carry =0;
        
        for (last element -> first element : digits){
            sum = carry + digits[i];
            if (sum>9){
                ans.push_back(0);
                carry = 1;
                continue;
            }
            else{
                ans.push_back(sum);
                carry = 0;
            }
        }
        
        */
        
        int carry = 0;
        int sum;
        vector<int> ans;
        int len = digits.size();
        
        for (int i=len-1;i>=0;i--){
            if (i==(len-1)){
                sum = digits[i] + 1;
            }
            else{
                sum = carry + digits[i];
            }
            
            if (sum>9){
                carry = 1;
                ans.push_back(0);
            }
            else{
                carry = 0;
                ans.push_back(sum);
            }
        }
        
        if (carry==1){
            ans.push_back(1);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};