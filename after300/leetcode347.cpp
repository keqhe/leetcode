
struct myCmp {
  bool operator()(const pair<int, int>& p1, const pair<int, int>&p2) const {
      return p1.first < p2.first;
  }  
};

class Solution {
public:
    //https://discuss.leetcode.com/topic/44313/3-ways-to-solve-this-problem/2
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto x : nums)
            m[x] ++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> maxheap;//less is maxheap
        for (auto& kv : m) {
            maxheap.push(make_pair(kv.second, kv.first));
        }
        int count = 0;
        vector<int> res;
        while (!maxheap.empty()) {
            count ++;
            auto x = maxheap.top();
            maxheap.pop();
            res.push_back(x.second);
            if (count == k)
                return res;
        }
        return res;
    }
};
