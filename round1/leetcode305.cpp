
class Solution {
public:
    //union find algorithm
    //union is O(1), find is O(logN) on average with pass compression optimization
    int tmp[4][2] = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};//must specify size in C++
    int find(vector<int> & roots, int id) {
        while (id != roots[id]) {
            roots[id] = roots[roots[id]];//path compression
            id = roots[id];
        }
        return id;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m <= 0 || n <= 0)
            return res;
        vector<int> roots (m*n, -1);//-1 mean non-island set
        int island_cnt = 0;
        for (auto & p : positions) {
            int i = p.first;
            int j = p.second;
            int root = i*n + j;
            roots[root] = root; //new island;
            
            island_cnt ++;
            
            for (auto & e : tmp) {
                int x = i + e[0];
                int y = j + e[1];
                int nb_pos = x*n + y;
                if (x < 0 || y < 0 || x >= m || y >= n || roots[nb_pos] == -1)// roots[nb] == -1, non-island cells
                    continue;
                
                int nb_root = find(roots, nb_pos);
                if (root != nb_root) {
                    roots[root] = nb_root;//merge two trees
                    root = nb_root;//current tree's root is the joined tree's root;
                    island_cnt --;
                }
            }
            
            res.push_back(island_cnt);
            
        }
        return res;
    }
};
