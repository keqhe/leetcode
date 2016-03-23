
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> combine;
        int i = 0;
        int j = 0;
        while (i <= m -1) {
            if (j <= n -1) {
                if (nums2[j] < nums1[i]) {
                    combine.push_back(nums2[j]);
                    j ++;
                }
                else {
                    combine.push_back(nums1[i]);
                    i ++;
                }
            }
            else {
                combine.push_back(nums1[i]);
                i ++;
            }
        }
        while (j <= n -1) {
            combine.push_back(nums2[j]);
            j ++;
        }
        nums1 = combine;
    }
};
