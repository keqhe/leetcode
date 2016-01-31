#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode() {left = NULL; right = NULL;}
	TreeNode(int v) {val = v; left = NULL; right = NULL;}
};

class BST{
public:
	void insert_iterative(struct TreeNode * & root, int x) {

		struct TreeNode * start = root;
		struct TreeNode * parent;
		struct TreeNode * newnode;
		if (!root) {
			root = new TreeNode(x);
			return;
		}	

		while(start) {
			parent = start;
			if (x > start->val)
				start = start->right;
			else if (x < start->val)
				start = start->left;
			else
				return;
		}
		//cout << "create new node ..." << endl;
		newnode = new TreeNode(x);
		if (parent->val > x)
			parent->left = newnode;
		else 
			parent->right = newnode;
		
	}
	struct TreeNode * insert_iterative2(struct TreeNode ** root, int key) {
		struct TreeNode ** p = root;
		struct TreeNode * keep = *root;
		if (!(*p)) {
			*p = new TreeNode(key);
			return *p;
		}
		while (*p) {
			if ((*p)->val < key)
				*p = (*p)->right;
			else if ((*p)->val > key)
				*p = (*p)->left;
			else
				return keep;
		}
		*p = new TreeNode(key);
		return keep;
	}
	void insert_recursive(struct TreeNode * &root, int x) {
		if (!root) {
			root = new TreeNode(x);
			return;		
		}
		if (root->val < x)
			insert_recursive(root->right, x);
		else if (root->val > x)
			insert_recursive(root->left, x);
		//else
		//	return;
	}
	struct TreeNode * locate_recursive(struct TreeNode * root, int key) {
		if (!root)
			return NULL;
		if (root->val == key)
			return root;
		else if (root->val < key)
			return locate_recursive(root->right, key);
		else
			return locate_recursive(root->left, key);
	}

	struct TreeNode * locate_iterative(struct TreeNode * root, int key) {
		while(root) {
			if (root->val == key)
				return root;
			else if (root->val < key)
				root = root->right;
			else
				root = root->left;
		} 
		return root;
	}
	int getHeight(struct TreeNode * root) {
		if (!root)
			return 0;
		return max(getHeight(root->left), getHeight(root->right)) + 1; 
	}

	int countNodes(struct TreeNode * root) {
		if (!root)
			return 0;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
	void preorder_traversal(struct TreeNode * root) {
		if (root) {
			cout << root->val << ' ';
			preorder_traversal(root->left);
			preorder_traversal(root->right);
		}
	}

	void preorder_iterative(struct TreeNode * root) {
		stack<struct TreeNode*> s;
		while(!s.empty() || root) {
			if (root) {
				cout << root->val << ' ';
				if (root->right)
					s.push(root->right);
				root = root->left;	
			}
			else {
				root = s.top();
				s.pop();
			}
		}
	}	
	void inorder_traversal(struct TreeNode * root) {
		if (root) {
			inorder_traversal(root->left);
			cout << root->val << ' ';
			inorder_traversal(root->right);
		}
	}

	void inorder_iterative(struct TreeNode * root) {
		stack<struct TreeNode *> s;
		while(!s.empty() || root) {
			if (root) {
				s.push(root);
				root = root->left;
			}	
			else {
				root = s.top();
				s.pop();
				cout << root->val << ' ';
				root = root->right;
			}
		}
	}
	void postorder_traversal(struct TreeNode * root) {
		if (root) {
			postorder_traversal(root->left);
			postorder_traversal(root->right);
			cout << root->val << ' ';
		}
	}

	void postorder_iterative(struct TreeNode * root) {
		stack<struct TreeNode *> s;
		struct TreeNode * last = NULL;
		while (!s.empty() || root) {
			if (root) {
				if (root->right)
					s.push(root->right);
				s.push(root);
				root = root->left;	
			}
			else {
				root = s.top();
				if (root->right && last != root->right)
					root = root->right;
				else {
					cout << root->val << endl;
					s.pop();
					last = root;
				}
			}
		}
	}

	struct TreeNode * findParent(struct TreeNode * root, int key) {
		struct TreeNode * p = root;
		struct TreeNode * q = nullptr;
		while (p) {
			if (p->val < key) {
				q = p;
				p = p->right;
			}
			else if (p->val > key) {
				q = p;
				p = p->left;
			}
			else 
				break;
		}
		return q;
		
	}
	struct TreeNode * findRightMost(struct TreeNode * root) {
		while(root->right) {
				root = root->right;
		}
		return root;
	}
	/*
	void remove(struct TreeNode * & root, int key) {
		struct TreeNode * p = locate_recursive(root, key);
		if (p) {
			if (!p->left && !p->right) {
				if (p != root) {
					struct TreeNode * par = findParent(key);
					if (par->val < key)
						par->right = NULL;
					else 
						par->left = NULL;
				}
				else {
					root = NULL;
				}
				delete p;
			}
			else if (!p->left && p->right) {//right is non-NULL
				if (p != root) {
					struct TreeNode * par = findParent(key);
					if (par->val < key)
						par->right = p->right;
					else
						par->left = p->right;
				}
				else {
					root = NULL;
				}
				delete p;
			}
			else if (!p->right && p->left) {//left is non-NULL
				if (p != root) {
					struct TreeNode * par = findParent(key);
					if (par->val < key) 
						par->right = p->left;
					else
						par->left = p->left;
				}
				else 	
					root = NULL;
				delete p;
			}
			else {//both are non-NULL
				struct TreeNode * par = findParent(key);
				struct TreeNode * rightmost = findRightMost(p->left);
				p->val = rightmost->val;
				if (par != p)
					par->right = rightmost->left;
				else
					par->left = rightmost->left;
			}
		}
	}*/
	void destory_bst(struct TreeNode * root) {//post order
		if (root) {
			destory_bst(root->left);
			destory_bst(root->right);
			delete root;
		}
	}

	//BFS and DFS

	//form binary trees from array, Serialize and deserilize
};

int main() {
	class BST t;
	struct TreeNode * tn = nullptr;
	struct TreeNode * tf;
	/*	
	t.insert_recursive(tn, 2);
	t.insert_recursive(tn, 1);
	t.insert_recursive(tn, 3);
	t.insert_recursive(tn, 0);	
	*/

	
	tn = t.insert_iterative2(&tn, 3);
        t.insert_iterative(tn, 1);
        t.insert_iterative(tn, 2);
	t.insert_iterative(tn, 4);
	t.insert_iterative(tn, 6);
	tn = t.insert_iterative2(&tn, 5);	
	//t.preorder_traversal(tn);
	//cout << endl;
	//t.postorder_traversal(tn);
	//cout << endl;
	t.inorder_traversal(tn);
	cout << endl;
	t.inorder_iterative(tn);
	cout << endl;
	t.preorder_traversal(tn);
        cout << endl;
	t.preorder_iterative(tn);
	cout << endl;
	t.postorder_traversal(tn);
        cout << endl;
	//t.postorder_iterative(tn);
	cout << endl;

	tf = t.findParent(tn, 2);
	if (tf)
		cout << "find parent node " << tf->val << endl;	
	tf = t.locate_recursive(tn, 100);
	if (tf)
		cout << tf->val << endl;

	tf = t.locate_iterative(tn, 100);
        if (tf)
                cout << tf->val << endl;

	cout << "the height of the BST is " << t.getHeight(tn) << endl;
	
	cout << "the number of nodes in this BST is " << t.countNodes(tn) << endl;
	if (tn)
		cout << "root of the BST is " << tn->val << endl;
	cout << "destory the BST now..." << endl;
	t.destory_bst(tn);
	tn = nullptr;
	return 0;
}
