class Solution {
    
private:
    void dfs(vector<vector<pair<int,int>>> &graph, vector<bool> &visited, int node, int totaltime, vector<int> &reachtime, vector<bool>&todo){
        
        if (totaltime > reachtime[node]){
            return ;
        }
        
        visited[node] = true;
        todo[node] = true;
        reachtime[node] = min(reachtime[node], totaltime);
        
        int maxtime = totaltime;
        
        for (auto p : graph[node]){
            if (!todo[p.first]){
                dfs(graph, visited, p.first, totaltime + p.second, reachtime, todo);
            }
        }
        
        todo[node] = false;
    }
    
    void createGraph(vector<vector<pair<int,int>>> &graph, vector<vector<int>> &times){
        
        for (int i=0;i<times.size();i++){
            graph[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        
        createGraph(graph,times);
        vector<int> reachtime(n+1, INT_MAX);
        vector<bool> visited(n+1,false); // once and for all visited
        vector<bool> todo(n+1, false); // to mark true within single dfs
        
        dfs(graph,visited, k, 0, reachtime, todo);
        
        for (int i=1;i<=n;i++){
            if (!visited[i]){
                return -1;
            }
        }
        int maxtime = 0;
        for (int i=1;i<=n;i++){
            maxtime = max(maxtime, reachtime[i]);
        }
        
        return maxtime;
    }
};