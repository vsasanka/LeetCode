class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        vector<int> prefix(arr.size(), 0);
        
        prefix[0] = arr[0];
        
        for (int i=1; i<arr.size(); i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        int s = 0;
        
        for (int i=0; i<arr.size(); i++){
            for (int j=i; j<arr.size(); j += 2){
                s += prefix[j] - prefix[i] + arr[i];
            }
        }
        
        return s;
    }
};