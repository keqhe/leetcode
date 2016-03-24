
class Solution {
public:
    bool hasCycle(vector<list<int>>&adj, vector<int> & visited, int parent, int u) {
        if (visited[u] == -1)
            return true;
        if (visited[u] == 1)
            return false;
        visited[u] = -1;
        for (auto it = adj[u].begin(); it != adj[u].end(); it ++) {
            //if (parent != *it && hasCycle(adj, visited, u, *it)) //if it is undirected graph
            if (hasCycle(adj, visited, u, *it)) //if it is directed graph
                return true;
        }
        visited[u] = 1;
        return false;
    }
    //note this is directed graph
    bool canFinish_dfs(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0 || numCourses == 1)
            return true;
        vector<list<int>> adj(numCourses, list<int>());
        for (auto e : prerequisites) {
            int a = e.first;
            int b = e.second;
            adj[b].push_back(a);
        }
        vector<int> visited (numCourses, false);
        for (int i = 0; i < numCourses; i ++) {
            if (hasCycle(adj, visited, -1, i))
                return false;
        }
        return true;
    }
    //BFS can also do this problem, 
    //see ref: https://leetcode.com/discuss/82347/java-easy-version-to-understand
    //the key idea is to manage the indegree of a vertex
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0 || numCourses == 1)
            return true;
        vector<int> inDegree(numCourses, 0);
        for (auto e : prerequisites) {
            int a = e.first;
            int b = e.second;
            inDegree[a] ++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) //courses depends on 0 other courses
                q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();//curr should have indegree of 0
            q.pop();
            for (int i = 0; i < prerequisites.size(); i ++) {
                if (prerequisites[i].second == curr) {
                    inDegree[prerequisites[i].first] --;
                    if (inDegree[prerequisites[i].first] == 0)
                        q.push(prerequisites[i].first);
                }
            }
        }
        for (int i = 0; i < numCourses; i ++)
            if (inDegree[i] != 0)
                return false;
        return true;
    }
};
