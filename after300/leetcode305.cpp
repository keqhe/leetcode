

struct Node {
  int rank;
  int root;
  Node() {
      rank = 0;
      root = -1;
  }
  void operator=(const Node &n) {
      this->rank = n.rank;
      this->root = n.root;
  }
};
class Solution {
public:
    //find with path compression
    int find(vector<Node>&uf, int index) {
        if (index != uf[index].root)
            uf[index].root = find(uf, uf[index].root);
        return uf[index].root;
    }
    bool merge(vector<Node>&uf, int index1, int index2) {
        int root1 = find(uf, index1);
        int root2 = find(uf, index2);
        if (root1 == root2)
            return false;
        else {
            if (uf[root1].rank > uf[root2].rank) {
                uf[root2].root = root1;
            }
            else if (uf[root2].rank > uf[root1].rank) {
                uf[root1].root = root2;
            }
            else {
                uf[root2].root = root1;
                uf[root1].rank ++;
            }
        }
        return true;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m == 0 || n == 0 || positions.empty())
            return res;
        vector<Node> uf(m*n);
        int island_count = 0;
        vector<vector<int>> temp = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < positions.size(); i ++) {
            int x = positions[i].first;
            int y = positions[i].second;
            int index = x*n + y;
            uf[index].root = index;
            island_count ++;
            for (auto t : temp) {
                int x2 = x + t[0];
                int y2 = y + t[1];
                int index2 = x2*n + y2;
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && uf[index2].root != -1) {
                    if (merge(uf, index, index2)) {
                        island_count --;
                    }
                }
            }
            res.push_back(island_count);
        }
        return res;
    }
};
