
class Solution {
public:
    //[1,2,3,4,5]
    //[0,1,2,4,5]
    //[100]
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int l = 0;
        int r = citations.size()-1;
        int last = 0;
        while (l <= r) {//think l <= r, instead of l < r, consider case [1]
            int mid = l + (r - l)/2;
            if (citations[mid] >= citations.size()-mid) {
                last = citations.size()-mid;
                r = mid;
                if (l == r) //avoid dead loop
                    break;
            }
            else {
                l = mid + 1;
            }
        }
        return last;
    }
};
