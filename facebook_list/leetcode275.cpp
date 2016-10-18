
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int l = 0;
        int r = citations.size()-1;
        int size = citations.size();
        int res = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (citations[mid] >= size-mid) {
                res = size-mid;
                cout << res << endl;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};
