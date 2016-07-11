
//http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
//union by rank, path compression

//unoin by rank, path compression, the time complexity is O(m) where m is the number of operations.
struct Subset {
  int root;
  int rank;
  Subset() {
      root = -1;
      rank = 0;
  }
};
class Solution {
    public:
    int find(vector<Subset>& uf, int index) {
       if (index != uf[index].root)
          uf[index].root = find(uf, uf[index].root);//path compression
       return uf[index].root;
    }
    bool merge(vector<Subset> & uf, int index1, int index2) {
        int root1 = find(uf, index1);
        int root2 = find(uf, index2);
        if (root1 == root2)
            return false;
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
        return true;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m == 0 || n == 0 || positions.empty())
            return res;
        vector<Subset> uf(m*n);
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int count = 0;
        for (auto pos : positions) {
            int x1 = pos.first;
            int y1 = pos.second;
            count ++;
            int index1 = x1*n + y1;
            int root1 = index1;
            uf[index1].root = root1;
            for (auto t : temp) {
                int x2 = x1+t[0];
                int y2 = y1+t[1];
                int index2 = x2*n+y2;
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && uf[index2].root != -1) {
                    if (merge(uf, index1, index2)) {
                        count --;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
/*class Solution {
public:
    int find(vector<int> & roots, int x) {
        while (x != roots[x]) {
            roots[x] = roots[roots[x]];//path compression
            x = roots[x];
        }
        return x;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m == 0 || n == 0 || positions.empty())
            return res;
        vector<int> roots(m*n, -1);
        int temp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        for (auto p : positions) {
            int x = p.first;
            int y = p.second;
            count ++;
            int curr_root = n*x + y;
            roots[curr_root] = curr_root;
            for (auto t : temp) {
                int x2 = x + t[0];
                int y2 = y + t[1];
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && roots[x2*n+y2] != -1) {
                    int x2_y2_root = find(roots, x2*n+y2);
                    if (x2_y2_root != curr_root) {
                        roots[curr_root] = x2_y2_root;//union
                        curr_root = x2_y2_root;
                        count --;
                    }
                }
            } 
            res.push_back(count);
        }
        return res;
    }
};*/
