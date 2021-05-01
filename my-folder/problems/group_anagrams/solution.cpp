class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // create copy
        
        // sort each element of copy
        
        // compare each element with each other... similar ones found add them to a vector
        // and push to answer. Take a bool array, mark true for all those which have been evaluted
        // already
        
        vector<string> copy;
        vector<string> group;
        vector<vector<string>> ans;
        
        for (int i=0;i<strs.size();i++){
            copy.push_back(strs[i]);
        }
        
        vector<bool> flags(strs.size(), false);
        
        for (int i=0;i<strs.size();i++){
            sort(copy[i].begin(),copy[i].end());
        }
        
        
        
        for (int i=0;i<copy.size();i++){
            if (flags[i]){
                continue;
            }
            
            group.push_back(strs[i]);
            flags[i] = true;
            
            for (int j=i+1;j<copy.size();j++){
                if (copy[i].compare(copy[j])==0){
                    group.push_back(strs[j]);
                    flags[j]=true;
                }
            }
            ans.push_back(group);
            group.clear();
        }
        
        return ans;
    }
};