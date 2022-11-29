class RandomizedSet {
    
    vector<int> rs;
    unordered_map<int,int> mp;
    vector<int> rem;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        
        mp[val] = rs.size();
        rs.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        
        int last = rs[rs.size()-1];
        
        rs[mp[val]] = last;
        mp[last] = mp[val];
        mp.erase(val);
        rs.pop_back();
        return true;
    }
    
    int getRandom() {
        return rs[rand()%rs.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */