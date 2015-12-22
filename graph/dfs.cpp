#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

/* time complexity is O(V+E)
0--------1
|
|
|        /\
2--------3
*/
class Graph {
private:
	int V;
	vector<list<int>> adj; //vector of adjacency list
	vector<int> color;
	vector<int> parent;
	vector<int> discover;//timestamp of discovering a vertex
	vector<int> finish;	//timestamp of finishing visiting a vertex
	int time = 0;
public:
	Graph(int V);
	void addEdge(int v, int w);//all of w is adjacent to v
	void dfs(vector<int> & res);
	void dfs_visit(int u, vector<int> & res);
	void printAdj();
};

Graph::Graph(int V) {
	this->V = V;
	adj.resize(V, list<int>());
	color.resize(V, 0);//0 is white
	parent.resize(V, -1);
	discover.resize(V, 0);
	finish.resize(V, 0);
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::printAdj() {
	for (int i = 0; i < adj.size(); i ++) {
		cout << "vertex " << i << " ; ";
		for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it ++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
}

void Graph::dfs(vector<int> & res) {
	for (int i = 0; i < adj.size(); i ++) {
		color[i] = 0;
		discover[i] = 0;
		finish[i] = 0;
		parent[i] = -1;
	}

	time = 0;
	for (int i = 0; i < adj.size(); i ++) {
		if (color[i] == 0) {
			dfs_visit(i, res);
		}
	}
	
}

void Graph::dfs_visit(int u, vector<int> & res) {
	time += 1;
	discover[u] = time;
	color[u] = 1;
	res.push_back(u);
	for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
		if (color[*it] == 0) {
			parent[*it] = u;
			dfs_visit(*it, res);			
		}
	}
	time += 1;
	finish[u] = time;
}

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}
int main() {
	class Graph g(4);
	g.addEdge(0, 2);
	g.addEdge(0, 1);

	g.addEdge(1, 0);

	g.addEdge(2, 0);
	g.addEdge(2, 3);
	
	g.addEdge(3, 2);
	g.addEdge(3, 3);

	g.printAdj();

	vector<int> res;
	g.dfs(res);
	printVector(res);
	return 0;	
}
