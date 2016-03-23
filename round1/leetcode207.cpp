
class Solution {
public:
    //key: detect cycle in a DAG (directed acyclic graph)
    //ref: http://www.programcreek.com/2014/05/leetcode-course-schedule-java/
    //ref: http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    
    bool dfs(vector<list<int>> & adj, int i, vector<bool> & recurStack, vector<bool> & color) {
        
        if (recurStack[i] == true)
            return false;
        color[i] = true;
        recurStack[i] = true;
        for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it ++) {
            if (!dfs(adj, *it, recurStack, color))
                return false;
        }
        recurStack[i] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.empty())
            return true;
        vector<list<int>> adj (numCourses, list<int>());
        
        for (int i = 0; i < prerequisites.size(); i ++) {
            int a = prerequisites[i].first;
            int b = prerequisites[i].second;
            adj[b].push_back(a);
        }
        
        vector<bool> recurStack (numCourses, false);
        vector<bool> color (numCourses, false);
        for (int i = 0; i < numCourses; i ++) {
            
                if (color[i] == false && !dfs(adj, i, recurStack, color)) 
                    return false;
        }
        
        return true;
    }
};
