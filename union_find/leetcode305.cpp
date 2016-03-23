
class Solution {
public:
    //wiki, union find: http://www.algorithmist.com/index.php/Union_Find
    //This is a common way to find connectivity between nodes, or to find connected components. 
    /*explnation of path compression:
    The second optimization is called path compression. It attempts to flatten the tree structure as much as possible whenever a find operation is performed. The basic idea is that as we traverse the parent pointers to the root, since all of the elements found along the way share the same root, then the parent of those elements might as well be the root itself. Thus we perform one traversal to find out what the root is, and then we perform a second traversal, setting each node's parent pointer to the root. This has the effect of majorly flattening the structure, decreasing the time required for future operations. Using this heuristic alone has a running time to O(logn) per operation, amortized. 
    */
    int temp[4][2] = {{-1,0},{1,0}, {0, -1}, {0, 1}};
    int find(vector<int> & roots, int id) {
        while (id != roots[id]) {
            roots[id] = roots[roots[id]];//path compression
            id = roots[id];
        }
        return id;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (positions.empty())
            return res;
        
        vector<int> roots(m*n, -1);//-1 means non-island cells
        int count = 0;
        for (auto p : positions) {
            int i = p.first;
            int j = p.second;
            count ++;
            int root = i*n + j;
            roots[root] = root;
            
            for (auto t: temp) {
                int x = i + t[0];
                int y = j + t[1];
                if (x >= 0 && x < m && y >= 0 && y < n && roots[x*n+y] != -1) {
                    int id = x*n + y;
                    int id_root = find(roots, id);
                    if (root != id_root) {
                        roots[root] = id_root;//union
                        root = id_root;
                        count --;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
/*
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
*/
