#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        for (int i = 1; i < costs.size(); i ++) {
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        
        return min(min(costs[costs.size()-1][0], costs[costs.size()-1][1]), costs[costs.size()-1][2]);
    }
};

int main() {
	class Solution sn;
	vector<vector<int>> costs;
	vector<int> tmp = {1,2,3};
	costs.push_back(tmp);
	tmp = {4,5,6};
	costs.push_back(tmp);
	cout << sn.minCost(costs) << endl;
	return 0;
}
