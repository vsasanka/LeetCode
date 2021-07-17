class Solution {
    
private:
    bool isAnagram(unordered_map<char, int> &map1, unordered_map<char, int> &map2){
        
        for (auto e: map1){
            if (e.second != map2[e.first]){
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mapp;
        unordered_map<char, int> maps;
        vector<int> ans;
        
        if (s.size() < p.size()){
            return ans;
        }
        
        for (int i=0; i<p.size(); i++){
            mapp[p[i]]++;
            maps[s[i]]++;
        }
        
        for (int i=0; i<s.size() - p.size()+1; i++){
            if (isAnagram(mapp,maps)){
                ans.push_back(i);
            }
            
            if (i+p.size() < s.size()){
                maps[s[i]]--;
                maps[s[i+p.size()]]++;
            }
        }
        
        return ans;
    }
};