#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Solution {
public:
    //hasCycle is topological sort, DFS, check whether a cycle exists and at the same records a possible solution
    bool hasCycle(vector<list<int>>&adj, vector<int>&visited, int u, list<int>&path) {
        if (visited[u] == -1)
            return true;
        if (visited[u] == 1)
            return false;
        visited[u] = -1;
        for (auto it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (hasCycle(adj, visited, *it, path))
                return true;
        }
        visited[u] = 1;
        path.push_front(u);//topological sort
        return false;
    }
    vector<int> findOrder_dfs(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
        vector<list<int>> adj(numCourses, list<int>());
        
        for (auto e : prerequisites) {
            int a = e.first;
            int b = e.second;
            adj[b].push_back(a);
        }
        vector<int> visited(numCourses, false);
        list<int> path;
        for (int i = 0; i < numCourses; i ++) {
            if (hasCycle(adj, visited, i, path))
                return res;
        }
        for (auto x : path)
            res.push_back(x);
        return res;
    }
    //BFS can also do topological sort on directed graph
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
            
        queue<int> q1;
        queue<int> q2;
        vector<int> inDegree(numCourses, 0);
        for (auto e : prerequisites) {
            int a = e.first;
            int b = e.second;
            inDegree[a] ++;
        }
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) {
                q1.push(i);
                q2.push(i);
            }
        }
        while (!q1.empty()) {
            int curr = q1.front();//vertex curr has indegree of 0
            cout << "CURR:" << curr << endl;
            q1.pop();
            for (int i = 0; i < prerequisites.size(); i ++) {
                if (prerequisites[i].second == curr) {
                    inDegree[prerequisites[i].first] --;
                    if (inDegree[prerequisites[i].first] == 0) {
                        q1.push(prerequisites[i].first);
                        q2.push(prerequisites[i].first);
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] != 0)
                return res;
        }
        /*when using queues, the following error, i sometimes make....
        cout << q2.size() << endl;
        for (int i = 0; i < q2.size(); i ++) {
            int a = q2.front();
            q2.pop();
            res.push_back(a);
        }
        cout << res.size() << endl;
        */
        //it should be
        int qsize = q2.size();
        for (int i = 0; i < qsize; i ++) {
            int a = q2.front();
            q2.pop();
            res.push_back(a);
        }
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
