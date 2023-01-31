class Solution {
public:
    bool isCycle(vector<vector<bool>> &graph, int node, vector<bool> &todo, vector<bool> &visited){
        if (todo[node]) return true;

        if (visited[node]) return false;

        bool cycle = false;
        visited[node] = true;
        todo[node] = true;

        for (int i=0; i<graph.size(); i++){
            if (graph[node][i]) cycle = cycle || isCycle(graph, i, todo, visited); 
        }

        todo[node] = false;

        return cycle;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> graph(numCourses, vector(numCourses, false));

        for (auto c: prerequisites){
            graph[c[1]][c[0]] = true;
            // graph[c[1]][c[0]] = true;
        }

        vector<bool> visited(numCourses, false);
        vector<bool> todo(numCourses, false);

        for (int i=0; i<numCourses; i++){
            if (!visited[i] && isCycle(graph, i, todo, visited)) return false; 
        }

        return true;
    }
};