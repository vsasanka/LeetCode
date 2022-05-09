class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int availcap = capacity;
        int steps = 0;
        
        for (int i=0; i<plants.size()-1; i++){
            availcap -= plants[i];
            if (availcap < plants[i+1]){
                steps += (i+1)*2;
                availcap = capacity;
            }
        }
        
        steps += plants.size();
        
        return steps;
    }
};