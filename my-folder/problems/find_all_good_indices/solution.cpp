class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> inc(nums.size(), 1);
        int num = 1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i] <= nums[i-1]){
                num++;
                inc[i] = num;
            }
            else{
                num = 1;
            }
            // cout << num << " ";
        }
        // cout << endl;
        
        // cout << 1 << endl;
        
        vector<int> dec(nums.size(), 1);
        num = 1;
        for (int i=nums.size()-2; i>=0; i--){
            if (nums[i] <= nums[i+1]){
                num++;
                dec[i] = num;
            }
            else{
                num = 1;
            }
            // cout << num << " ";
        }
        // cout << endl;
        
        vector<int> ans;
        
        for (int i=k; i<nums.size()-k; i++){
            if (inc[i-1] >= k && dec[i+1] >= k){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

/*
[878724,201541,179099,98437,35765,327555,475851,598885,849470,943442]
1 2 3 4 5 1 1 1 1 1
1 1 1 1 6 5 4 3 2 1
*/