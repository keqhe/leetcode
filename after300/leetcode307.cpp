
struct SegmentTreeNode {
  int s;
  int e;
  int sum;
  struct SegmentTreeNode* left;
  struct SegmentTreeNode* right;
  SegmentTreeNode(int s_, int e_) {
      s = s_;
      e = e_;
      sum = 0;
      left = nullptr;
      right = nullptr;
  }
};

class SegmentTree {
public:
    SegmentTree(vector<int>&nums) {
        root = BuildSegmentTree(nums, 0, nums.size()-1);
        cout << "build okay" << endl;
    }  
    void Update(int pos, int val) {
        Update(root, pos, val);
        cout << "update okay" << endl;
    }
    int SumRange(int i, int j) {
        int res = SumRange(root, i, j);
        cout << "sumRange okay" << endl;
        return res;
    }
private:
    SegmentTreeNode* root;
    SegmentTreeNode* BuildSegmentTree(vector<int>&nums, int l, int r) {
        if (l > r)
            return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(l, r);
        if (l == r)
            root->sum = nums[l];
        else {
            int mid = l + (r-l)/2;
            root->left = BuildSegmentTree(nums, l, mid);
            root->right = BuildSegmentTree(nums, mid+1, r);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }
    void Update(SegmentTreeNode*root, int pos, int val) {
        if (root->s == root->e) {
            root->sum = val;
        }
        else {
            int mid = root->s + (root->e - root->s)/2;
            if (pos <= mid) {
                Update(root->left, pos, val);
            }
            else {
                Update(root->right, pos, val);
            }
            root->sum = root->left->sum + root->right->sum;
        }
    }
    int SumRange(SegmentTreeNode*root, int s, int e) {
        if (root->s == s && root->e == e) {
            return root->sum;
        }
        int mid = root->s + (root->e - root->s)/2;
        if (e <= mid) {
            return SumRange(root->left, s, e);
        }
        else if (s >= mid+1) {
            return SumRange(root->right, s, e);
        }
        else {
            return SumRange(root->left, s, mid) + SumRange(root->right, mid+1, e);
        }
    }
};
class NumArray {
public:
    //segment tree implementation
    SegmentTree *st;
    NumArray(vector<int> &nums) {
        st = new SegmentTree(nums);
    }
    void update(int i, int val) {
        st->Update(i, val);
        
    }
    int sumRange(int i, int j) {
        return st->SumRange(i, j);
        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
