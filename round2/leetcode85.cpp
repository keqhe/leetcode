
class Solution {
public:
    //hmm, a hard problem, based on leetcode 84 (calculate the max rectangle in histogram)
    //see ref:https://leetcode.com/discuss/52670/solution-based-maximum-rectangle-histogram-with-explanation
    //helper is leetcode 84, calculate maximal rectangle in a histogram
    int helper(vector<int> & hist) {
        if (hist.empty())
            return 0;
        stack<int> st;//hist[index] are non-decreasing (index are in the order when they are pushed)
        int i = 0;
        int maxArea = 0;
        while (i < hist.size()) {
            if (st.empty() || hist[st.top()] <= hist[i]) {
                st.push(i);
                i ++;
            }
            else {
                int tp = st.top();
                st.pop();
                
                //note at this point, we know that hist[st.top()] (if st.top() exists)  
                // <= hist[tp] and hist[tp] < hist[i]
                //we are trying to calculate the area size when hist[tp] as the smallest bar
                int area = hist[tp]*(st.empty() ? i : i-1-st.top());
                maxArea = max(maxArea, area);
            }
        }
        
        while (!st.empty()) {
            int tp = st.top();
            st.pop();
                
            //note at this point, we know that hist[st.top()] (if st.top() exists)  
            // <= hist[tp] and hist[tp] < hist[i]
            //we are trying to calculate the area size when hist[tp] as the smallest bar
            int area = hist[tp]*(st.empty() ? i : i-1-st.top());
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    void resetRow(vector<int> & row, vector<vector<char>> & matrix, int r) {//r is row number
        for (int j = 0; j < row.size(); j ++) {
            if (matrix[r][j] - '0' == 1) {
                row[j] += 1;
            }
            else
                row[j] = 0;
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix[0].size();//n is the number of cols
        vector<int> row (n, 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            resetRow(row, matrix, i);
            for (int k = 0; k < row.size(); k ++)
                cout << row[k] << " ";
            cout << endl;
            int area = helper(row);
            cout << "area " << area << endl;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
