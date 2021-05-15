/*class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    }
};*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        
        vector<bool> todo(numCourses,false);
        vector<bool> done(numCourses,false);
        
        for (int i=0;i<numCourses;i++){
            if (!acyclic(g,todo,done,i)) return false;
        }
        
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        
        for (auto k : prerequisites){
            g[k[1]].push_back(k[0]);
        }
        
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>&todo, vector<bool>&done, int node) {
        if (todo[node]){
            return false;
        }
        
        if (done[node]){
            return true;
        }
        
        done[node] = todo[node] = true;
        
        for (auto v : g[node]){
            if (!acyclic(g,todo,done,v)) return false;
        }
        
        todo[node] = false;
        return true;
    }
};