
class Solution {
public:
    int maximalRectangle2(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        int max_area = 0;
        for (int i = 0; i < m; i ++) {
            int curr_left = 0;
            int curr_right = n;
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                }
                else {
                    height[j] = 0;
                }
            }
            
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curr_left);
                }
                else {
                    curr_left = j+1;
                    left[j] = 0;
                }
            }
            
            for (int j = n-1; j >= 0; j --) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curr_right);
                }
                else {
                    curr_right = j;
                    right[j] = n;
                }
            }
            
            for (int j = 0; j < n; j ++) {
                if (right[j] > left[j]) {
                    max_area = max(max_area, height[j]*(right[j]-left[j]));
                }
            }
        }
        return max_area;
    }
    int helper(vector<int>&nums) {
        if (nums.empty())
            return 0;
        stack<int> st;
        int max_area = 0;
        int i = 0;
        for(; i < nums.size(); i ++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                int top = st.top();
                st.pop();
                int area;
                if (st.empty()) {
                    area = nums[top]*i;
                }
                else {
                    area = nums[top]*(i-st.top()-1);
                }
                max_area = max(max_area, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int area;
            if (st.empty()) {
                area = nums[top]*i;
            }
            else {
                area = nums[top]*(i-st.top()-1);
            }
            max_area = max(max_area, area);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> row(n, 0);
        int max_area = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1') {
                    row[j] += 1;
                }
                else {
                    row[j] = 0;
                }
            }
            max_area = max(max_area, helper(row));
        }
        return max_area;
    }
};
