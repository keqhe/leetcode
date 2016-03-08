#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    //first idea is DFS, see ref: https://leetcode.com/discuss/68233/java-dfs-solution-and-seeking-for-a-binary-search-solution
    //because the black pixels are connected, so this is why DFS is possible
    //DFS time complexity is O(m*n), i.e., the board size
    int minX = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int minY = numeric_limits<int>::max();
    int maxY = numeric_limits<int>::min();
    void dfs(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] == '0')
            return;
        image[x][y] = '0'; //similar to visited, mark as visited,
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        
        dfs(image, x-1, y);
        dfs(image, x+1, y);
        dfs(image, x, y-1);
        dfs(image, x, y+1);
    }
    int minArea_dfs(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        dfs(image, x, y);
        return (maxX-minX+1)*(maxY-minY+1);
    }
    
    //binary search, see ref: https://leetcode.com/discuss/68246/c-java-python-binary-search-solution-with-explanation
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        int m = image.size();
        int n = image[0].size();
        
        //find the top most x value
        int top = 0;
        int bottom = x;
        int index_x1;
        while (top <= bottom) {
            int mid = top + (bottom - top)/2;
            bool hasOne = false;
            for (int j = 0; j < n; j ++) {
                if (image[mid][j] == '1') {
                    hasOne = true;
                    break;
                }
            }
            if (hasOne) {
                index_x1 = mid;
                bottom = mid - 1;
            }
            else 
                top = mid + 1;
        }
        
        //find bottom most x value
        top = x;
        bottom = m-1;
        int index_x2;
        while (top <= bottom) {
            int mid = top + (bottom - top)/2;
            bool hasOne = false;
            for (int j = 0; j < n; j ++) {
                if (image[mid][j] == '1') {
                    hasOne = true;
                    break;
                }
            }
            if (hasOne) {
                index_x2 = mid;
                top = mid + 1;
            }
            else 
                bottom = mid - 1;
        }
      
        //find left most y value
        int left = 0;
        int right = y;
        int index_y1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            bool hasOne = false;
            for (int i = 0; i < m; i ++) {
                if (image[i][mid] == '1') {
                    hasOne = true;
                    break;
                }
            }
            if (hasOne) {
                index_y1 = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        //find bottom most y value
        left = y;
        right = n-1;
        int index_y2;
        while (left <= right) {
            int mid = left + (right - left)/2;
            bool hasOne = false;
            for (int i = 0; i < m; i ++) {
                if (image[i][mid] == '1') {
                    hasOne = true;
                    break;
                }
            }
            if (hasOne) {
                index_y2 = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        cout << index_x1 << " " << index_x2 << endl;
        cout << index_y1 << " " << index_y2 << endl;
        return (index_x2-index_x1+1)*(index_y2-index_y1+1);
    }
};

int main() {
	class Solution sn;
	return 0;
}
