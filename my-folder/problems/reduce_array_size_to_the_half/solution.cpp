class Solution {
    
    
public:
    bool sortmethod(int a, int b){
        return a > b;
    }
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        
        for (int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        
        vector<int> counts;
        
        for (auto a: freq){
            counts.push_back(a.second);
        }
        
        sort(counts.begin(), counts.end(), [](int a, int b){ return a>b;});
        int sum = 0;
        for (int i=0; i<counts.size(); i++){
            sum += counts[i];
            
            // cout << counts[i] << " ";
            
            if (2*sum >= arr.size()){
                return i+1;
            }
        }
        
        return arr.size();
    }
};