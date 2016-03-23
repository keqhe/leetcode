
class Solution {
public:
    //ref; https://leetcode.com/discuss/52670/solution-based-maximum-rectangle-histogram-with-explanation
    int checkRow (vector<int> & height) {//the solution in Maximum Rectangle in Histogram
        stack<int> st;//index are in this stack
        int max_area = 0;
        int curr_area;
        int bar;//bar index
        int i = 0;
        
        //cout << "height[0] is " << height[0] << endl;
        while (i < height.size()) {
            if (st.empty() || height[st.top()] <= height[i]) {
                st.push(i);
                i ++;
            }
            else {
                bar = st.top();
                st.pop();
                if (!st.empty()) {
                    curr_area = height[bar]* (i - 1 - st.top());
                }
                else {
                    curr_area = height[bar]* (i);
                }
                max_area = max(max_area, curr_area);
            }
        }
        //now i should be height.size() + 1;
        cout << "i is " << i << endl;
        while (!st.empty()) {
            bar = st.top();
            st.pop();
            //cout << "height[bar] is " << height[bar] << endl;
            if (!st.empty()) {
                curr_area = height[bar]* (i - 1 - st.top());
            }
            else {
                curr_area = height[bar]* (i);
            }
            max_area = max(max_area, curr_area);
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        vector<int> height (matrix[0].size(), 0);
        
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            //update height
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else 
                    height[j] = 0;
            }
            
            //cout << "height[0] is " << height[0] << endl;
            maxArea = max(maxArea, checkRow(height));
        }
        
        return maxArea;
    }
};
