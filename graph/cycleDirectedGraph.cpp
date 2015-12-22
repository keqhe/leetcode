#include<iostream>
#include<vector>
#include<list>

using namespace std;
/*time complexity is O(V+E)*/
/*cycle 1->0->2->3->1
0<--------1
|       /|
|      /
|     /
\/   /
2   /
|  /
| /
\/
3

4------>5
*/
class Graph {
private:
	vector<list<int>> adj;
	int V; //number of vertices
	vector<int> color;
	vector<bool> recurStack;
public:
	Graph (int V);
	void addEdge(int v, int w);
	void printAdj();
	bool hasCycle();
	bool dfs_visit(int u);
};

Graph::Graph(int V) {
	this->V = V;
	adj.resize(V, list<int>());
	color.resize(V, 0);
	recurStack.resize(V, false);
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

bool Graph::hasCycle() {
	list<int> res;
	for (int i = 0; i < adj.size(); i ++) {
		color[i] = 0;
	}

	for (int i = 0; i < adj.size(); i ++) {
		if (color[i] == 0 && dfs_visit(i)) 
			return true;
	}

	return false;
}

bool Graph::dfs_visit(int u) {
	if (recurStack[u])
		return true;//back edge found
	color[u] = 1;
	recurStack[u] = true;
	for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
		if (dfs_visit(*it))
			return true;
	}
	recurStack[u] = false;
	return false;
}


int main() {
	class Graph g(6);

	g.addEdge(1, 0);

	g.addEdge(0, 2);
	
	g.addEdge(2, 3);

	g.addEdge(3, 1);

	g.addEdge(4, 5);
	
	g.printAdj();

	cout << g.hasCycle() << endl;
	return 0;
}
