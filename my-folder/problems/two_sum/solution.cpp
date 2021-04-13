class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mapping;
        vector<int> temp;
        
        for (int i=0;i<nums.size();i++){
            if (mapping.find(target - nums[i])!=mapping.end()){
                
                map<int,int>::iterator it;
                it = mapping.find(target-nums[i]);
                temp.push_back(it->second);
                temp.push_back(i);
                break;
            }
            else{
                mapping.insert(pair<int,int> (nums[i],i));
            }
        }
        return temp;
    }
};