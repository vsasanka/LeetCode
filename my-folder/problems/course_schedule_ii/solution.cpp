class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses,false);
        vector<bool> done(numCourses,false);
        vector<int> order;
        
        for (int i=0;i<numCourses;i++){
            if (!done[i] && !acyclic(g, todo,done,order,i)) return {};
        }
        
        reverse(order.begin(),order.end());
        return order;
    }
    
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        graph g(numCourses);
        
        for (auto v : prerequisites){
            g[v[1]].push_back(v[0]);
        }
        
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, vector<int>& order, int node){
        if (todo[node]){
            return false;
        }
        
        if (done[node]){
            return true;
        }
        
        done[node] = todo[node] = true;
        
        for (auto v : g[node]){
            if (!acyclic(g, todo, done, order, v)) return false;
        }
        
        order.push_back(node);
        todo[node] = false;
        return true;
    }
    
};