class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>> > ds;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // cout << key << " " << value << endl;
        ds[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        // vector<pair<string,int>> vec = ds[key];
        
//         for (auto p: vec){
//             cout << p.second << " ";
//         }
        
        if (ds[key].size() == 0) return "";
        
        int left = 0, right = ds[key].size() - 1;
        int mid;
        
        if (timestamp < ds[key][0].second) return "";
        
        while (left < right){
            mid = left + (right - left + 1)/2;
            
            if (ds[key][mid].second < timestamp){
                left = mid;
            }
            else if (ds[key][mid].second > timestamp){
                right = mid - 1;
            }
            else{
                return ds[key][mid].first;
            }
        }
        
        // cout << ds[key][left].first << " ";
        
        return ds[key][left].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */