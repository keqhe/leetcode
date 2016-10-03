
struct Node {
  int sum;
  pair<int, int> p;
  Node (const int& x, const pair<int, int>& y) {
      sum = x;
      p = y;
  }
};
struct Mycmp {
    bool operator() (const Node & n1, const Node & n2) {
        return n1.sum < n2.sum;
    }
};

struct Node2 {
    int x;
    int y;
    int array2_index;
    Node2(int x, int y, int index) : x(x), y(y), array2_index(index) {};
};

struct Mycmp2 {
  bool operator() (const Node2 & n1, const Node2 & n2) {
      return (n1.x + n1.y) > (n2.x + n2.y);
  }  
};

class Solution {
public:
    //http://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
    //learn: how to define custom comparator in c++ for priority_queue(heap)
    //time complexity is O(m*n*logk), note this is max heap
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, Mycmp> pq;
        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int curr_sum = nums1[i] + nums2[j];
                auto p = make_pair(nums1[i], nums2[j]);
                pq.push(Node(curr_sum, p));
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        cout << "debug" << endl;
        vector<pair<int, int>> res;
        while (!pq.empty()) {
            auto &x = pq.top();
            res.push_back(x.p);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    //an O(k*logK) solution: https://discuss.leetcode.com/topic/50885/simple-java-o-klogk-solution-with-explanation
    vector<pair<int, int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node2, vector<Node2>, Mycmp2> pq;
        int m = nums1.size();
        int n = nums2.size();
        vector<pair<int, int>> res;
        if (m == 0 || n == 0 || k == 0)
            return res;
            
        for (int i = 0; i < min(m, k); i ++) {
            pq.push(Node2(nums1[i], nums2[0], 0));
        }
        
        for (int i = 0; i < k && !pq.empty(); i ++) {
            auto & curr = pq.top();
            res.emplace_back(make_pair(curr.x, curr.y));
            if (curr.array2_index+1 < n) {
                pq.push(Node2(curr.x, nums2[curr.array2_index+1], curr.array2_index+1));
            }
            pq.pop();
        }
        return res;
    }
};
