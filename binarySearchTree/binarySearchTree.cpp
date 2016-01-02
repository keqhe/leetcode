#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<limits>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode () {
		left = NULL;
		right = NULL;
	}
	TreeNode (int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

class BSearchTree {
public:
	struct TreeNode * myroot;
	BSearchTree() {
		myroot = NULL;
	}
	BSearchTree(int x) {
		myroot = new TreeNode(x);
	}
	~BSearchTree() {
		destory(myroot);
	}
	void destory(struct TreeNode * root) {
		if (root == NULL)
			return;
		destory(root->left);
		destory(root->right);
		delete root;
	}
	void insert_recur(struct TreeNode * & r, int x) {//note reference
		if (!r) {
			r = new TreeNode(x);
			return;
		}	
		if (x > r->val)
			insert_recur(r->right, x);
		else if (x < r->val)
			insert_recur(r->left, x);
	}

	void insert_iter(struct TreeNode * & r, int x) {
		if (!r) {
			r = new TreeNode (x);
			return;	
		}
		struct TreeNode * parent = NULL;
		struct TreeNode * start = r;
		while(start) {
			if (start->val < x) {
				parent = start;
				start = start->right;
			}
			else if (start->val > x) {
				parent = start;
				start = start->left;
			}
			else 
				return;
		}
		start = new TreeNode(x);
		if (parent->val < x)
			parent->right = start;
		else
			parent->left = start;
	}
	//https://www.youtube.com/watch?v=gcULXE7ViZw
	struct TreeNode * findMin(struct TreeNode* root) {
		if (root == NULL)
			return root;
		while (root->left) {
			root = root->left;
		}
		return root;
	}
	struct TreeNode * remove (struct TreeNode * root, int val) {
		if (root == NULL) return root;
		else if (val < root->val) root->left = remove(root->left, val);
		else if (val > root->val) root->right = remove(root->right, val);
		else {
			//case 1, No child
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
			}
			//case 2, 1 child
			else if (root->left == NULL) {
				struct TreeNode * temp = root;
				root = root->right;
				delete temp;
			}
			//case 2, 1 child
			else if (root->right == NULL) {
				struct TreeNode * temp = root;
				root = root->left;
				delete temp;
			}
			//case 3, 2 children
			else {
				struct TreeNode * temp = findMin(root->right);
				root->val = temp->val;
				root->right = remove(root->right, temp->val);
			}
			return root;
		}
	}
	void inorder_recur(struct TreeNode * r) {
		if (!r)
			return;
		inorder_recur(r->left);
		cout << r->val << ' ';
		inorder_recur(r->right);
	}
	void preorder_recur(struct TreeNode * r) {
		if (!r)
			return;
		cout << r->val << ' ';
		preorder_recur(r->left);
		preorder_recur(r->right);
	}

	void postorder_recur(struct TreeNode * r) {	
		if (!r)
			return;
		postorder_recur(r->left);
		postorder_recur(r->right);
		cout << r->val << ' ';
	}
	void inorder_iter(struct TreeNode * r) {
		stack<struct TreeNode *> st;
		while (!st.empty() || r) {
			if (r) {
				st.push(r);
				r = r->left;
			}
			else {
				r = st.top();
				cout << r->val << ' ';
				st.pop();
				r = r->right;
			}
		}
	}
	void preorder_iter(struct TreeNode * r) {
		stack<struct TreeNode *> s;
		while(!s.empty() || r) {
			if (r) {
				cout << r->val << ' ';
				s.push(r->right);
				r = r->left;	
			}
			else {//reached the left most
				r = s.top();//start to process the right subtrees
				s.pop();
			}
		}
	}
	void postorder_iter(struct TreeNode * r) {
		if (!r)
			return;
		stack<struct TreeNode *> st;
		struct TreeNode * prev = NULL;
		st.push(r);
		while (!st.empty()) {
			struct TreeNode * curr = st.top();
			//traverse down
			if (!prev || prev->left == curr || prev->right == curr) {
				if (curr->left)
					st.push(curr->left);
				else if (curr->right)
					st.push(curr->right);
				else {
					cout << curr->val << ' ';
					st.pop();
				}
			}
			//we are traversing up from the left
			else if (curr->left == prev) {
				if (curr->right)
					st.push(curr->right);
				else {
					cout << curr->val << ' ';
                                        st.pop();
				}
			}
			//traverse up from the right
			else if (curr->right == prev) {
				cout << curr->val << ' ';
                                st.pop();
			}
			//
			prev = curr;
		}
	}

	//BFS, level by level
	void bfs(struct TreeNode * r) {
		if (!r)
			return;
		queue<struct TreeNode*> q;
		q.push(r);
		while(!q.empty()) {
			struct TreeNode * t = q.front();
			q.pop();
			cout << t->val << ' ';
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
	}

	void dfs(struct TreeNode *r) {
		if (!r) 
			return;
		stack<struct TreeNode*> s;
		while(!s.empty() || r) {
			if (r) {
				cout << r->val << ' ';
				s.push(r->right);
				r = r->left;
			}
			else {//left has reached leaf
				r = s.top();
				s.pop();
			}
		}
	}

	void dfs2(struct TreeNode * r) {
		if (!r)
			return;
		stack<struct TreeNode*> s;
		s.push(r);
		while(!s.empty()) {	
			struct TreeNode * curr = s.top();
			s.pop();
			cout << curr->val << ' ';
			if (curr->left)
				s.push(curr->left);
			if (curr->right)
				s.push(curr->right);
		}
	}
	//serilize and deserialize
	void serilize(struct TreeNode * root, vector<string> & v) {
		if (!root) {
			v.push_back("#");
			return;
		}
		v.push_back(to_string(root->val));
		serilize(root->left, v);
		serilize(root->right, v);
		
	}
	struct TreeNode* deserilize(vector<string> & v, int &index) {
		if (index > v.size() - 1 || v[index] == "#")
			return NULL;
		struct TreeNode * root = new TreeNode(stoi(v[index]));
		index ++;
		root->left = deserilize(v, index);
		index ++;
		root->right = deserilize(v, index);

		return root;
	}
	//store a BST in an array, preorder, no markers needed
	void preorder_store(struct TreeNode * root, vector<int> & nums) {
		if (!root)
			return;
		nums.push_back(root->val);
		if (root->left)
			preorder_store(root->left, nums);
		if (root->right)
			preorder_store(root->right, nums);
	}

	struct TreeNode * preorder_reconstrcut(vector<int> & nums, int &index, int key, int min, int max) {
		cout << "call:: index: " << index << ", key:" << key << ", min: " << min << ", max: " << max << endl;
		if (index >= nums.size())
			return NULL;
		struct TreeNode * root = NULL;
		if ( key > min && key < max) {
			cout << "build a new node with key " << key << endl << endl;
			root = new TreeNode(key);
			index ++;
			//cout << "process index " << index << ' ';
			if (index < nums.size())
				root->left = preorder_reconstrcut(nums, index, nums[index], min, key);
			if (index < nums.size())
				root->right = preorder_reconstrcut(nums, index, nums[index], key, max);
		}
		return root;
	}
};

void printVector(vector<string> &v) {
	for (int i = 0; i < v.size(); i ++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

void printIntVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++)
		cout << nums[i] << ' ';
	cout << endl;
}
int main() {
	class BSearchTree bt;
	bt.insert_recur(bt.myroot, 2);
	bt.insert_recur(bt.myroot, 1);
	bt.insert_recur(bt.myroot, 5);
	bt.insert_recur(bt.myroot, 3);
	bt.insert_iter(bt.myroot, 4);
	
	bt.inorder_recur(bt.myroot);
	cout << endl;
	bt.inorder_iter(bt.myroot);
	cout << endl;
	bt.preorder_recur(bt.myroot);
        cout << endl;
	bt.preorder_iter(bt.myroot);
	cout << endl;
	bt.postorder_recur(bt.myroot);
        cout << endl;
	bt.postorder_iter(bt.myroot);
	cout << endl;

	cout << "breadth-first-search..." << endl;
	bt.bfs(bt.myroot);
	cout << endl;
	cout << "deepth-first-search..." << endl;
	bt.dfs(bt.myroot);
	cout << endl;
	cout << "depth-first-search2..." << endl;
	bt.dfs2(bt.myroot);
	cout << endl;

	//serilize and deserilize a binary tree
	vector<string> v;
	bt.serilize(bt.myroot, v);
	printVector(v);
	int index = 0;
	struct TreeNode *troot= bt.deserilize(v, index);
	bt.dfs(troot);
	cout << endl;

	//preorder store a BST and reconstruct it from the array
	vector<int> pre;
	bt.preorder_store(bt.myroot, pre);
	cout << "preorder store a BST into an array..." << endl;
	printIntVector(pre);
	cout << "reconstuct the BST from the preorder store array..." << endl;
	int index2 = 0;
	struct TreeNode * prestore = bt.preorder_reconstrcut(pre, index2, pre[0], numeric_limits<int>::min(), 
						numeric_limits<int>::max());
	bt.dfs(prestore);
	cout << endl;	
	return 0;
}
