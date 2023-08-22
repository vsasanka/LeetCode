class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList[] graph = new ArrayList[numCourses];

        for (int i=0; i<numCourses; i++){
            graph[i] = new ArrayList();
        }

        for (int i=0; i<prerequisites.length; i++){
            graph[prerequisites[i][1]].add(prerequisites[i][0]);
        }

        boolean[] visited = new boolean[numCourses];
        boolean[] todo = new boolean[numCourses];

        for (int i=0; i<numCourses; i++){
            if (dfs(graph, i, visited, todo)){
                return false;
            }
        }

        return true;
    }

    private boolean dfs(ArrayList[] graph, int parent, boolean[] visited, boolean[] todo){
        if (todo[parent]) return true;

        if (visited[parent]) return false;

        visited[parent] = true;
        todo[parent] = true;

        boolean res = false;

        for (int i=0; i<graph[parent].size(); i++){
            res = res || dfs(graph, (int)graph[parent].get(i), visited, todo);
        }

        todo[parent] = false;

        return res;
    }
}