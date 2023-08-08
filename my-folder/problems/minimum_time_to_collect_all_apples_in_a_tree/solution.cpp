class Tree{
public:
    int val;
    vector<Tree*> children;
    Tree(){
        
    }
    Tree(int val){
        this->val = val;
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, Tree*> treeMap;
        vector<bool> isVisited(n, false);
        constructTreeToN(n, treeMap);
        makeTree(edges, treeMap);
        int ans = traversal(treeMap[0], hasApple, isVisited);
        return ans == 0? 0 : ans-1;
    }

private:
    void constructTreeToN(int n, unordered_map<int, Tree*> &treeMap){
        for (int i=0; i<n; i++){
            treeMap[i] = new Tree(i);
        }
    }

    void makeTree(vector<vector<int>>& edges, unordered_map<int, Tree*> &treeMap){
        for (auto e: edges){
            treeMap[e[0]]->children.push_back(treeMap[e[1]]);
            treeMap[e[1]]->children.push_back(treeMap[e[0]]);
        }
    }

    int traversal(Tree* node, vector<bool>& hasApple, vector<bool> &isVisited){
        int addTime = 0;
        int time = 0;
        int totalTime = 0;
        isVisited[node->val] = true;
        // bool childApple = false;

        for (auto c : node->children){
            if (isVisited[c->val]) continue;
            time = traversal(c, hasApple, isVisited);
            totalTime += time;
            if (time > 0) addTime++;
        }

        if (totalTime > 0) return totalTime + addTime + 1;
        else if (hasApple[node->val]) return 1;
        return 0;
        // return totalTime;
    }
};