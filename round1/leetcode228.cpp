
class Solution {
public:
    //initially i made two mistakes 1)forgot the last string 2)I thought i need to add "" explicitly,,,
    //and this test case: [-2147483648,-2147483647,2147483647]
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if (nums.size() == 0)
            return v;
        long xmin = nums[0];
        long xmax = nums[0];
        long prev = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            long t = nums[i];
            if (t - prev <= 1) {//continious, NOTE INT_MAX - INT_MIN, so we need LONG
                if (t >= xmax)
                    xmax = t;
                prev = t;
            }
            else {
                string s;
                if (xmin != xmax)
                    s = to_string(xmin) + "->" + to_string(xmax);
                else 
                    s = to_string(xmin);
                    
                v.push_back(s);
                xmin = t;
                xmax = t;
                prev = t;
            }
        }
        
        //last string
        string s;
        if (xmin != xmax)
            s = to_string(xmin) + "->" + to_string(xmax);
        else 
            s = to_string(xmin);
        v.push_back(s);
        cout << numeric_limits<int>::min() << ' ' << numeric_limits<int>::max() << endl;
        return v;
    }
};
