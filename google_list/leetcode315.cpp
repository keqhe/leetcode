
struct Node {
  int val;
  int idx;
  Node() : val(0), idx(-1) {}
  Node(int value, int index) : val(value), idx(index) {}
  bool operator<(const Node & x) {
      return val < x.val;
  }
  Node&operator=(const Node & x) {
      val = x.val;
      idx = x.idx;
      return *this;
  }
};

class Solution {
public:
    void merge(vector<Node> & arr, int l, int mid, int r, vector<int> & res) {
        vector<Node> hold(r-l+1);
        int i = l;
        int j = mid+1;
        int k = 0;
        int count = 0;
        while (i <= mid && j <= r) {
            while (j <= r && arr[j] < arr[i]) {
                hold[k++] = arr[j++];
                count ++;
            }
            res[arr[i].idx] += count;
            hold[k++] = arr[i++];
        }
        while (i <= mid) {
            res[arr[i].idx] += count;
            hold[k++] = arr[i++];
        }
        while (j <= r) {
            hold[k++] = arr[j++];
        }
        for (int x = 0; x < hold.size(); x ++) {
            arr[l+x] = hold[x];
        }
    }
    void mergeSort(vector<Node> & arr, int l, int r, vector<int> & res) {
        if (l >= r)
            return;
        if (l < r) {
            int mid = l + (r-l)/2;
            mergeSort(arr, l, mid, res);
            mergeSort(arr, mid+1, r, res);
            merge(arr, l, mid, r, res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        vector<Node> arr;
        for (int i = 0; i < nums.size(); i ++) {
            arr.emplace_back(nums[i], i);
        }
        
        res.resize(nums.size(), 0);
        mergeSort(arr, 0, nums.size()-1, res);
        return res;
    }
};
