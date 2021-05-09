class Solution {
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if (k==nums.size()){
            return nums;
        }
        
        map<int,int> freqTable;
        
        for (int i :nums){
            freqTable[i]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for (auto& it : freqTable){
            pq.push(make_pair(it.second,it.first));
        }
        
        vector<int> result;
        
        while (k){
            result.push_back((pq.top()).second);
            pq.pop();
            k--;
        }
        
        return result;
    }
};