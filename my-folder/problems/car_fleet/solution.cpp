class Solution {
    
private:
    bool static compare(pair<int,int> &a, pair<int,int> &b){
        return a.first < b.first;
    }
    
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        float time;
        int fleets = speed.size();
        vector<pair<int,int>> pos_speed;
        
        for (int i=0; i<speed.size(); i++){
            pos_speed.push_back({position[i], speed[i]});
        }
        
        sort(pos_speed.begin(), pos_speed.end(), compare);
        
        for (int i=0; i<position.size(); i++){
            // cout << pos_speed[i].first << " " << pos_speed[i].second << " ";
            time = (float)(target - pos_speed[i].first)/(float)pos_speed[i].second;
            
            // cout << time << " ";
            
            while (!st.empty() && st.top() <= time){
                fleets--;
                cout << st.top() << " ";
                st.pop();
            }
            
            st.push(time);
        }
        
        return fleets;
    }
};

/*
0 3 5 8 10

*/