
struct Node {
    Node(int v, int i) : val(v), index(i) {}
    int val;
    int index;
    bool operator<(const Node&n) {
        return this->val < n.val;
    }
    Node& operator=(const Node& n) {
        this->val = n.val;
        this->index = n.index;
        return *this;
    }
};
class Solution {
public:
    void merge(vector<Node>&nums, int l, int m, int r, vector<int>&res) {
        vector<Node> tmp1;
        vector<Node> tmp2;
        for (int i = l; i <= m; i ++) {
            tmp1.push_back(nums[i]);
        }
        for (int i = m+1; i <= r; i ++) {
            tmp2.push_back(nums[i]);
        }
        int size1 = m-l+1;
        int size2 = r-m;
        int i = 0;
        int j = 0;
        vector<Node> store;
        int count = 0;
        while (i < size1) {
            while (j < size2 && tmp2[j] < tmp1[i]) {
                store.push_back(tmp2[j]);
                j ++;
                count ++;
            }
            store.push_back(tmp1[i]);
            res[tmp1[i].index] += count;
            i ++;
        }
        while (j < size2) {
            store.push_back(tmp2[j]);
            j ++;
        }
        //cout <<"size1+size2 == r-l+1:" << (size1+size2 == r-l+1) << endl;
        //cout << "store.size == r-l+1: " << (store.size() == r-l+1) << endl;
        for (int i = 0; i < store.size(); i ++) {
            nums[i+l] = store[i];
        }
    }
    void mergeSort(vector<Node>&nums, int l, int r, vector<int>&res) {
        if (l < r) {
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid, res);
            mergeSort(nums, mid+1, r, res);
            merge(nums, l, mid, r, res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<Node> tmp;
        for (int i = 0; i < nums.size(); i ++) {
            tmp.emplace_back(Node(nums[i], i));
        }
        vector<int> res(nums.size(), 0);
        mergeSort(tmp, 0, tmp.size()-1, res);
        return res;
    }
};
