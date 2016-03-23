
class Solution {
public:
    //ref: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;
        
        int max_area = 0;
        int curr_area = 0;
        int bar_index;
        
        int i = 0;
        //for (; i < height.size(); ) {
        while (i < height.size()) {
            if (st.empty() || height[st.top()] <= height[i]) {
                st.push(i);
                i++;
            }
            else {//st.top() > height[i]
                bar_index = st.top();
                st.pop();
                if (!st.empty())
                    curr_area =  height[bar_index]*(i-1-st.top());
                else 
                    curr_area = height[bar_index]*i;    
                max_area = max(max_area, curr_area);
            }
        }
        cout << "debug..." << endl;
        while (!st.empty()) {//left bars height are increasing, 1, 2, 3 in this example
            bar_index = st.top();
            st.pop();
            if (!st.empty())
                curr_area =  height[bar_index]*(i-1-st.top());
            else 
                curr_area = height[bar_index]*i;    
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};
