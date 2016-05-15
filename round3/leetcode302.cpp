
class Solution {
public:
    //this problem DFS is easier
    int minX = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    
    int minY = numeric_limits<int>::max();
    int maxY = numeric_limits<int>::min();
    void dfs(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] == '0')
            return;
        image[x][y] = '0';//so that we do not visit it again
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        dfs(image, x-1, y);
        dfs(image, x+1, y);
        dfs(image, x, y-1);
        dfs(image, x, y+1);
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        dfs(image, x, y);
        cout << minX << " " << maxX << endl;
        cout << minY << " " << maxY << endl;
        return (maxX-minX+1)*(maxY-minY+1);
    }
};
