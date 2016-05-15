
class Solution {
public:
    bool dfs(vector<list<int>> & adj, int u, vector<int> & visited, vector<int> & res) {
        if (visited[u] == 1)
            return false;//no loop
        if (visited[u] == -1)
            return true;//there is a loop
        visited[u] = -1;
        for (auto x : adj[u]) {
            if (dfs(adj, x, visited, res))
                return true;
        }
        visited[u] = 1;//finished processing
        res.push_back(u);
        return false;
    }
    vector<int> findOrder_dfs(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
        if (numCourses == 1) {
            res.push_back(0);
            return res;
        }
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i ++)
                res.push_back(i);
            return res;
        }
        vector<list<int>> adj(numCourses, list<int>());
        for (auto p : prerequisites)
            adj[p.second].push_back(p.first);
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i ++) {
            if (visited[i] == 0)
                if (dfs(adj, i, visited, res)) {
                    vector<int> tmp;
                    return tmp;
                }
        }
        //no loop
        reverse(res.begin(), res.end());
        for (auto x : res)
            cout << x << " ";
        cout << endl;
        return res;
    }
    //method 2, BFS
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
        if (numCourses == 1) {
            res.push_back(0);
            return res;
        }
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i ++)
                res.push_back(i);
            return res;
        }
        
        vector<int> inDegree(numCourses, 0);
        for (auto p : prerequisites) {
            inDegree[p.first] ++;
        }
        
        queue<int> q;//all the nodes in q should have no dependency on others
        
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto p : prerequisites) {
                if (curr == p.second && inDegree[p.first] > 0) {
                    inDegree[p.first] --;
                    if (inDegree[p.first] == 0) {
                        q.push(p.first);
                        res.push_back(p.first);
                    }
                }
            }
        }
        for (auto x : inDegree) {
            if (x!= 0) {//there is a loop
                vector<int> tmp;
                return tmp;
            }
        }
        //reverse(res.begin(), res.end()); //think why we do not need to reverse it
        return res;
    }
};
