
class Solution {
public:
    //basically, if there is a loop in the directed graph, can not finish
    bool dfs(vector<list<int>> & adj, int u, vector<int> & visited) {
        if (visited[u] == 1)
            return false;
        if (visited[u] == -1)
            return true;//means there is a loop
        visited[u] = -1;//being processed
        for (auto x : adj[u]) {
            //if (visited[x] == 0) {//THIS IS WRONG, think why (we can not find the loop in this case)
                if (dfs(adj, x, visited))
                    return true;
        }
        visited[u] = 1;
        return false;
    }
    //the following version of BFS TLE, but i think the logic is correct
    bool bfs(vector<list<int>> & adj) {
        queue<int> q;
        int n = adj.size();
        for (int i = 0; i < n; i ++) {
            if (adj[i].empty())
                q.push(i);
        }
        while (!q.empty()) {
            int no_one_depend_on_me = q.front();
            q.pop();
            for (int i = 0; i < n; i ++) {
                list<int> curr_list = adj[i];
                auto it  = find(curr_list.begin(), curr_list.end(), no_one_depend_on_me);
                if (it != curr_list.end()) {
                    curr_list.erase(it);
                    if (curr_list.empty())
                        q.push(i);
                }
            }
        }
        for (auto l: adj)
            if (l.size() > 0)
                return false;
        return true;
    }
    bool canFinish_dfs(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.empty())
            return true;
        vector<list<int>> adj(numCourses, list<int>());
        for (auto p : prerequisites) {
            adj[p.second].push_back(p.first);
        }
        vector<int> visited(numCourses, 0);
        /*the dfs method*/
        for (int i = 0; i < numCourses; i ++) {
            if (visited[i] == 0)
                if (dfs(adj, i, visited))
                    return false;
        }
        return true;
    }
    //the faster BFS version, using a inDegree vector
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.empty())
            return true;
            
        vector<int> inDegree(numCourses, 0);
        for (auto p : prerequisites) {
            inDegree[p.first] ++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto p : prerequisites) {
                int c1 = p.first;
                int c2 = p.second;//c1 depends on c2
                if (c2 == curr) {
                    inDegree[c1] --;
                    if (inDegree[c1] == 0)
                        q.push(c1);
                }
            }
        }
        //finally, all nodes should have indegree of zero if we can finish
        for (auto x : inDegree)
            if (x != 0)
                return false;
        return true;
    }
};
