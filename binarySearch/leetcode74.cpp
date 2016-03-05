#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int bottom = m-1;
        int up = 0;
        
        int row = -1;
        while (up <= bottom) {
            int mid = up + (bottom-up)/2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]) {
                row = mid;
                break;
            }
            else if (target > matrix[mid][n-1])
                up = mid + 1;
            else if (target < matrix[mid][0])
                bottom = mid - 1;
        }
        if (row == -1)
            return false;
        int left = 0; 
        int right = n-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else 
                right = mid -1;
        }
        return false;
    }
};

int main() {
	class Solution sn;
	return 0;
}
