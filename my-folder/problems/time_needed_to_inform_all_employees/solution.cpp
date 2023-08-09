class Tree{
public:
    int time;
    vector<Tree*> children;

    Tree(){

    }

    Tree(int time){
        this->time = time;
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, Tree*> map;
        int maxTime = 0;

        makeMap(map, n, headID, informTime);
        makeTree(map, n, manager);

        maxMinutes(map[headID], 0, maxTime);
        return maxTime;
    }

private:

    void maxMinutes(Tree* root, int time, int &maxTime){
        if (root->children.size() == 0) return ;

        time += root->time;
        maxTime = max(maxTime, time);

        for (auto c: root->children){
            maxMinutes(c, time, maxTime);
        }
    }

    void makeMap(unordered_map<int, Tree*> &map, int n, int headID, vector<int>& informTime){
        for (int i=0; i<n; i++){
            map[i] = new Tree(informTime[i]);
        }
        map[-1] = NULL;
    }

    void makeTree(unordered_map<int, Tree*> &map, int n, vector<int>& manager){
        for (int i=0; i<n; i++){
            Tree* parent = map[manager[i]];
            Tree* child = map[i];
            if (parent != NULL) parent->children.push_back(child);
        }
    }
};