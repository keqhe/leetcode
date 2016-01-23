#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

class Solution {
public:
    //ref: https://leetcode.com/discuss/69079/concise-java-solution-based-on-dfs
    //ref: https://leetcode.com/discuss/56269/c-solution-dfs
    
    //detect cycle in an directed graph: http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    //detect cycle in an undirected graph: 
    bool dfs(int u, vector<list<int>> & adj, vector<int> & visited, int parent) {//return false, if there is a loop
        if (visited[u] == -1) //in stack, loop found, think color = grey
            return false;
        if (visited[u] == 1)//already visited, okay, think color = black
            return true;
        visited[u] = -1;//put in recursive stack
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (parent != *it && !dfs(*it, adj, visited, u))//should not check u's parent
                return false;
        }
        visited[u] = 1;
        return true;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0 && edges.empty())
            return true;
        vector<list<int>> adj (n, list<int>());
        vector<int> visited(n, 0);
        
        for (auto & e : edges) {
            int a = e.first;
            int b = e.second;
            adj[a].push_back(b);
            adj[b].push_back(a); //undirected graph
        }
        for (int i = 0; i < n; i ++) {
            cout << "vertex: " << i << " : ";
            for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it ++)
                cout << *it << " ";
            cout << endl;
        }
        for (int i = 0; i < n; i ++) {
            if (!dfs(i, adj, visited, -1))
                return false;
        }
        return edges.size() == n - 1;//the number of vertex should be (n-1)
    }
};

int main() {
	class Solution sn;
	int n = 5;
	vector<pair<int,int>> edges;
	edges.push_back(make_pair(0,1));
	edges.push_back(make_pair(0,2));
	edges.push_back(make_pair(0,3));
	edges.push_back(make_pair(1,4));
	cout << sn.validTree(n, edges) << endl;

	edges.clear();
	edges.push_back(make_pair(0,1));
	edges.push_back(make_pair(1,2));
	edges.push_back(make_pair(2,3));
	edges.push_back(make_pair(1,3));
	edges.push_back(make_pair(1,4));
	cout << sn.validTree(n, edges) << endl;
	return 0;	 
}
