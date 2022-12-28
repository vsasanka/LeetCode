class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count =0;
        
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int to_find = nums[i] + nums[j];
                
                auto val = lower_bound(nums.begin() + j+1, nums.end(), to_find);
                
                if (val != nums.end()){
                    count += static_cast<int>(val - (nums.begin() + j + 1));
                    // cout << nums[i] << " " << nums[j] << " " << *val << " " << count << endl;
                }
                else{
                    count += n - j - 1;
                }
            }
        }
        
        return count;
    }
};