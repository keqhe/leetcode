
class Solution {
public:
    //e.g., [1, 2, 4], 2
    //e.g., [1, 4], 1
    //e.g., [4], 1
    //[1, 2, 3, 4, 5, 6], 3
    //[3, 4, 5, 6]
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int left = 0;
        int right = size - 1;
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            int c = citations[mid];
            if (size - mid > c)
                left = mid + 1;
            else if (size - mid < c)
                right = mid - 1;
            else
                return size - mid;
        }
        
        return size - left;
    }
};
