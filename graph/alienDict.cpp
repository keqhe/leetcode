#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    //ref: https://leetcode.com/discuss/54549/java-toposort-solution-clean
    //ref: http://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
    //idea: topological sort
    void getCharSet(vector<string>& words, unordered_set<char> & se) {
        for (auto s : words) {
            for (auto c : s)
                se.insert(c);
        }
    }
    bool dfs(char u, unordered_map<char, list<char>> & adj, vector<int> & visited, string & res) {
        if (visited[u] == -1)
            return false;//loop detected
        if (visited[u] == 1)
            return true;//already checked and it is okay
        visited[u] = -1;
	if (adj.find(u) != adj.end()) {
        	for (list<char>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            		if (!dfs(*it, adj, visited, res))
                		return false;
        	}
	}
        visited[u] = 1;
        res += u;
        return true;
    }
    string alienOrder(vector<string>& words) {
        unordered_set<char> se;
        getCharSet(words, se);//find all chars in the word vector, use to keep track of orphan chars
        int size = se.size();
	cout << "size of this language is : " << size << endl;
	for (auto & c : se)
		cout << c << " ";
	cout << endl;

        unordered_map<char, list<char>> adj;
        //build adj list
        for (int i = 0; i < words.size() - 1; i ++) {
            for (int j = i+1; j < words.size(); j ++) {
                for (int k = 0; k < min(words[i].length(), words[j].length()); k ++) {
                    if (words[i][k] != words[j][k]) {
                        se.erase(words[i][k]);//delete the chars from char set
                        se.erase(words[j][k]);
                       
			//cout << "process :" << words[i] << " and " << words[j] << " ";
			//cout << words[i][k] << " != " << words[j][k] << endl;
 
                        if (adj.find(words[i][k]) == adj.end()) {
			    cout << "add new key into adj :" << words[i][k] << endl;
                            adj[words[i][k]].push_back(words[j][k]);
			    list<char> tmp = adj[words[i][k]];
			    cout << (tmp.front()) << endl;
			}
                        else {
                            list<char>::iterator it = find(adj[words[i][k]].begin(), adj[words[i][k]].end(), words[j][k]);
                            //if not in the adj list yet
                            if (it == adj[words[i][k]].end())
                                adj[words[i][k]].push_back(words[j][k]);
                        }
                        
                        break;
                    }
                }
            }
        }
	cout << "adj size is " << adj.size() << endl;
	cout << "char set current size is " << se.size() << endl;
	cout << "check adj list..." << endl;
	for (auto & i : adj) {
		cout << i.first << ":";
		for (auto & c : i.second)
			cout << c << " ";
		cout << endl;
	}
        //do topo sort
        vector<int> visited (256, 0);
        string res;
        for (auto & item : adj) {
            char ch = item.first;
	    cout << "DFSing " << ch << endl;
            if (!dfs(ch, adj, visited, res)) {
               	 cout << "loop detected in DAC" << endl;
		 return "";
	    }
        }
        cout << "debug..." << endl;
        //handle orphan chars
        for (auto & c : se) {
            res += c;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
	class Solution sn;
	vector<string> test = {"wrt","wrf","er","ett","rftt"};
	string res = sn.alienOrder(test);
	cout << res << endl;
	cout << endl << endl;
	test = {"axjvfmly","qvmontyiap","ihhdkals","gzdbwuqeej","ocd","gkspsmevgc","zyd","aeo","djp","wdhk","aumnj","hwazr"};
	res = sn.alienOrder(test);
	cout << res << endl;
	return 0;
}
