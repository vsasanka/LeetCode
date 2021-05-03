class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> ans;
        unordered_set<int> set;
        vector<vector<int>> ans1;
        
        if (nums.size()<3){
            return ans1;
        }
        
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<nums.size()-2;i++){
            // cout << nums[i] << endl;
            if (set.find(nums[i])!=set.end()){
                continue;
            }
            else{
                set.insert(nums[i]);
            }
            int k,j;
            j = i+1;
            k=nums.size()-1;
            
            while(j<k){
                if (nums[j]+nums[k]==(-1)*nums[i]){
                    // cout << nums[j] << " " << nums[k] << endl;
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    // v.sort(v.begin(),v.end());
                    ans.insert(v);
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k] < (-1)*nums[i]){
                    // cout << nums[j] << " " << nums[k] << endl;
                    j++;
                }
                else{
                    // cout << nums[j] << " " << nums[k] << endl;
                    k--;
                }
            }
        }
        
        
        
        for (auto x: ans){
            ans1.push_back(x);
        }
        
        return ans1;
    }
};
//        k    i j
// -4 -1 -1 0 1 2 