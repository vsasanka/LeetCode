class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<vector<int>> answer;
        
        if (nums.size()<4){
            return answer;
        }
        
        for (int i = 0; i < nums.size() - 3; i++){
            for (int j =i+1; j< nums.size() - 2; j++){
                int m,n;
                m = j + 1;
                n = nums.size() - 1;
                int sum1 = (nums[i] + nums[j]);
                
                while ( m < n){
                    if (nums[m] + nums[n] + sum1 == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[m]);
                        temp.push_back(nums[n]);
                        ans.insert(temp);
                        m++;
                        n--;
                    }
                    else if(nums[m] + nums[n] + sum1 < target){
                        m++;
                    }
                    else{
                        n--;
                    }
                }
            }
        }
        
        for (auto s : ans){
            answer.push_back(s);
        }
        
        return answer;
    }
};