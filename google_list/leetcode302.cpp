
class Solution {
public:
    void dfs(vector<vector<char>>& image, int x, int y, int &x_min, int &x_max, int &y_min, int &y_max) {
        int m = image.size();
        int n = image[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != '1')
            return;
        image[x][y] = '0';
        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_min = min(y_min, y);
        y_max = max(y_max, y);
        
        dfs(image, x-1, y, x_min, x_max, y_min, y_max);
        dfs(image, x+1, y, x_min, x_max, y_min, y_max);
        dfs(image, x, y-1, x_min, x_max, y_min, y_max);
        dfs(image, x, y+1, x_min, x_max, y_min, y_max);
        //image[x][y] = '1';// putting this WRONG
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        int x_min = numeric_limits<int>::max();
        int x_max = numeric_limits<int>::min();
        int y_min = numeric_limits<int>::max();
        int y_max = numeric_limits<int>::min();
        
        int m = image.size();
        int n = image[0].size();
        dfs(image, x, y, x_min, x_max, y_min, y_max);
        
        cout << x_min << " " << x_max << endl;
        cout << y_min << " " << y_max << endl;
        return (x_max-x_min+1)*(y_max-y_min+1);
        
    }
};
