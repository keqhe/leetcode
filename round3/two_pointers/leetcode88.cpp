
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //note below the way of movig data is WRONG, think why
        /*
        int i = 0;
        int j = n;
        while (i < m) {
            nums1[j++] = nums1[i++];
        }
        */
        for (int i = m-1; i >= 0; i --) {
            nums1[i+n] = nums1[i];
        }
        
        int k = 0;
        int i = n;
        int j = 0;
        while (i < m+n && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[k++] = nums1[i++];
            }
            else
                nums1[k++] = nums2[j++];
        }
        while (i < m+n) 
            nums1[k++] = nums1[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
};
