#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<limits>
#include<queue>
using namespace std;
/* time complexity is O(V + E)
0----1
|   
|  
| 
|           /\
2------------3 (3 has a cycle)
*/
class Graph { 
private:
	int V; //number of vertices
	vector<list<int>> adj;// pointer to the array containing the adjacency lists
	vector<int> color;//color, white and non-white
	vector<int> dist; //distance from the source
	vector<int> parent;
public:
	Graph (int V);
	void addEdge(int v, int w);
	vector<int> bfs(int s);
	void printAdj();
};

Graph::Graph(int V) {
	this->V = V;
	adj.resize(V, list<int>());
	color.resize(V, 0);
	dist.resize(V, numeric_limits<int>::max());
	parent.resize(V, -1);
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::printAdj() {
	for (int i = 0; i < adj.size(); i ++) {
		cout << "vertex " << i << " : ";
		for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
			cout << *it << ' ';
		cout << endl;
	}
}

vector<int> Graph::bfs(int s) { //s is the source
	vector<int> res;
	for (int i = 0; i < adj.size(); i ++) {
		if (i != s) {
			color[i] = 0;
			dist[i] = numeric_limits<int>::max();
		}
	}
	color[s] = 1;
	dist[s] = 0;
	parent[s] = -1;//NIL
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		cout << "visit vertex " << t << endl;
		res.push_back(t);	
		for (list<int>::iterator it = adj[t].begin(); it != adj[t].end(); it ++) {
			if (color[*it] == 0) {
				q.push(*it);
				cout << "push " << *it << " into queue" << " ; ";
				color[*it] = 1;
				dist[*it] = dist[t] + 1;
				parent[*it] = t;
			}
		}
		color[t] = 1;
		cout << endl;
	}	
	return res;
} 
int main() {
	class Graph g(4);
	g.printAdj();

	cout << endl;

	g.addEdge(0, 2);
	g.addEdge(0, 1);

	g.addEdge(1, 0);

	g.addEdge(2, 0);
	g.addEdge(2, 3);

	g.addEdge(3, 2);
	g.addEdge(3, 3);

	g.printAdj();

	vector<int> res = g.bfs(2);
	for (int i = 0; i < res.size(); i ++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;	
}
