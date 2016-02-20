#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<list>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //ref: https://leetcode.com/discuss/75054/5ms-java-clean-solution
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        //unordered_map<int, list<int>> m; //this is WRONG because the key is not in order
        map<int, list<int>> m;
        queue<pair<struct TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        int min_col = 0;
        int max_col = 0;
        while (!q.empty()) {
            pair<struct TreeNode*, int> curr = q.front();
            q.pop();
            struct TreeNode * p = curr.first;
            int col = curr.second;
            m[col].push_back(p->val);
            if (p->left) {
                q.push(make_pair(p->left, col-1));
                min_col = min(min_col, col-1);   
            }
            if (p->right) {
                q.push(make_pair(p->right, col+1));
                max_col = max(max_col, col+1);
            }
        }
        for (auto x : m) {
            vector<int> tmp;
            for (auto y : x.second) {
                //cout << y << " ";
                tmp.push_back(y);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
	struct TreeNode * p2 = new TreeNode(2);
	struct TreeNode * p1 = new TreeNode(1);
	struct TreeNode * p3 = new TreeNode(3);
	p2->left = p1;
	p2->right = p3;

	class Solution sn;
	vector<vector<int>> res = sn.verticalOrder(p2);
	for (auto x : res) {
		for (auto y : x) 
			cout << y << " ";
		cout << endl;
	}
	return 0;
}
