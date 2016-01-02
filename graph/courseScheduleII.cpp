#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

class Solution {
public:
    //DFS or BFS
    //first,  BFS, ref: http://www.programcreek.com/2014/06/leetcode-course-schedule-ii-java/
    vector<int> findOrder_bfs(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
        vector<int> pCounter (numCourses,  0);//record how many prerequisites each course has
        int len = prerequisites.size();
        for (int i = 0; i < len; i ++) {
            pCounter[prerequisites[i].first] ++;
        }
        
        //put all the courses which have 0 prerequisite into a queue
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (pCounter[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            res.push_back(a);
            
            for (int i = 0; i < len; i ++) {
                if (prerequisites[i].second == a) {
                    pCounter[prerequisites[i].first] --;

		    if (pCounter[prerequisites[i].first] == 0) {
                    	q.push(prerequisites[i].first);
                    }
                }
            }
        }
        
        if (res.size() == numCourses) {
            return res;
        }
        else {
            vector<int> tmp;
            return tmp;
        }
    }
    //dfs: ref: http://www.programcreek.com/2014/05/leetcode-course-schedule-java/
    bool dfs(int u, vector<list<int>> & adj, vector<int> & visited, vector<int> & res) {
        if (visited[u] == -1)
            return false;//loop detected;
        if (visited[u] == 1)
            return true; //already finished processed this vertex and no loop from this node
        visited[u] = -1;//in recursive stack
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (!dfs(*it, adj, visited, res))
                return false;
        }
        visited[u] = 1;//finished visiting
        res.push_back(u);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
        vector<int> visited (numCourses, 0);
        
        vector<list<int>> adj (numCourses, list<int>());
        for (int i = 0; i < prerequisites.size(); i ++) {
            int a = prerequisites[i].first;
            int b = prerequisites[i].second;
            adj[b].push_back(a);
        }
        
        for (int i = 0; i < numCourses; i ++) {
            if (!dfs(i, adj, visited, res)) {
                vector<int> tmp;
                return tmp;
            } 
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}
int main() {
	class Solution sn;
	vector<pair<int,int>> pv;
	pv.push_back(make_pair(0, 1));
	vector<int> res = sn.findOrder(2, pv);
	printVector(res);
	return 0;
}
