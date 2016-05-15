
struct Node {
  int val;
  int index;
  Node () {
      val = 0;
      index = -1;
  }
  Node(int v, int idx) {
      val = v;
      index = idx;
  }
  Node &operator=(const struct Node & t) {
      this->val = t.val;
      this->index = t.index;
      return *this;//note the answer in round II missed this, which is WRONG, adding this is correct
  }
  bool operator< (const struct Node & t) {
      return val < t.val;
  }
};

//there is a naive O(n^2) solution, which you should talk about
class Solution {
public:
    //merge sort and count
    void merge(vector<struct Node>& nums, int l, int r, int mid, vector<int> & res) {
        vector<struct Node> tmp(r-l+1);
        int i = l;
        int j = mid+1;
        int k = 0;
        int count = 0;
        while (i <= mid) {
            while (j <= r && nums[j] < nums[i]) {//if nums[j] < nums[i], then we must have nums[j] < nums[i+1]
                tmp[k++] = nums[j++];
                count ++;
            }
            tmp[k++] = nums[i];
            res[nums[i].index] += count;
            i ++;
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int p = l; p <= r; p ++) {
            nums[p] = tmp[p-l];
        }
    }
    void mergeSort(vector<struct Node>& nums, int l, int r, vector<int>& res) {
        if (l < r) {
            int mid = l + (r - l)/2;
            mergeSort(nums, l, mid, res);
            mergeSort(nums, mid+1, r, res);
            merge(nums, l, r, mid, res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        res.resize(nums.size(), 0);
        vector<struct Node> tmp;
        for (int i = 0; i < nums.size(); i ++) {
            struct Node n(nums[i], i);
            tmp.push_back(n);
        }
        mergeSort(tmp, 0, nums.size()-1, res);
        return res;
    }
};
