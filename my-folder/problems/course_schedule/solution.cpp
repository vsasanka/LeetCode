class Solution {
    
private:
    bool isCyclic(vector<vector<int>> &graph, vector<bool> &done, vector<bool> &todo, int node){
        // if this node was already seen within this dfs, then return false
        if (todo[node]){
            return true;
        }
        // mark the current node as visited
        if (done[node]){
            return false;
        }
        // 
        todo[node] = done[node] = true;
        
        for (auto n : graph[node]){
            if (isCyclic(graph, done,todo, n)) return true;
        }
        todo[node] = false;
        
        return false;
    }
    
    void createGraph(vector<vector<int>> &graph, vector<vector<int>> &prerequisites){
        // iterate across prerequisites and create graph
        
        for (int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        createGraph(graph, prerequisites);
        
        vector<bool> done(numCourses, false); // once and for all
        vector<bool> todo(numCourses, false); // used for each dfs
        
        for (int i=0;i<numCourses;i++){
            if (isCyclic(graph,done,todo,i)) return false;
        }
        
        return true;
    }
};