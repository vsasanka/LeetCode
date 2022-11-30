class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        
        for (int i=0; i<arr.size(); i++){
            freq1[arr[i]]++;
        }
        
        for (auto p : freq1){
            freq2[p.second]++;
            
            if (freq2[p.second] > 1) return false;
        }
        
        return true;
    }
};