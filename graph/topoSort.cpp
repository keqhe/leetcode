#include<iostream>
#include<vector>
#include<list>

using namespace std;
/*only for (direct acyclic graph) DAG*/
/*time complexity is O(V+E)*/
/*
0------->1
|
|
|
\/
2
|
|
\/
3

4------>5
*/
class Graph {
private:
	vector<list<int>> adj;
	int V; //number of vertices
	vector<int> color;
	vector<int> discover;
	vector<int> finish;
	vector<int> parent;
	int time = 0;
public:
	Graph (int V);
	void addEdge(int v, int w);
	void printAdj();
	list<int> topoSort();
	void dfs_visit(int u, list<int> & res);
};

Graph::Graph(int V) {
	this->V = V;
	adj.resize(V, list<int>());
	color.resize(V, 0);
	discover.resize(V, 0);
	finish.resize(V, 0);
	parent.resize(V, -1);
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

list<int> Graph::topoSort() {
	list<int> res;
	for (int i = 0; i < adj.size(); i ++) {
		color[i] = 0;
		parent[i] = -1;
	}

	for (int i = 0; i < adj.size(); i ++) {
		if (color[i] == 0) 
			dfs_visit(i, res);
	}

	return res;
}

void Graph::dfs_visit(int u, list<int> & res) {
	time += 1;
	discover[u] = time;
	color[u] = 1;
	for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
		if (color[*it] == 0) {
			parent[*it] = u;
			dfs_visit(*it, res);
		}
	}
	time += 1;
	finish[u] = time;
	res.push_front(u);
}

void printList(list<int> & nums) {
	for (list<int>::iterator it = nums.begin(); it != nums.end(); it ++) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main() {
	class Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	
	g.addEdge(2, 3);

	g.addEdge(4, 5);
	
	g.printAdj();

	list<int> res = g.topoSort();
	printList(res);
	return 0;
}
