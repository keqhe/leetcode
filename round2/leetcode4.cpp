
class Solution {
public:
    //hard problem
    //ref: http://articles.leetcode.com/find-k-th-smallest-element-in-union-of
    //ref: https://leetcode.com/discuss/2910/how-to-get-o-log-m-n-complexity-i-only-solved-it-in-o-m-n
    //ref: https://leetcode.com/discuss/74981/java-easy-version-to-understand
    //see this problem: find the k-th elements in the union of two sorted array
    int findKth(vector<int>& nums1, int m, vector<int>& nums2, int n, int k) {
        
        /* assert(i >= 0); assert(j >= 0); assert(i <= m); assert(j <= n);; 
        so i think i range is [0, m] and j range is [0, n]*/
        
        //l and r are the boundries of i, i is the index of A's element that satisfied the invariant (i + j = k – 1).
        int l = k - 1 - min(k - 1, n);//n here means when j = n
        int r = min(k, m);//fuck, this is the key
        
        while (l <= r) {
            //invarant i+j = k - 1;
            int i = l + (r-l)/2;
            int j = k-1-i;
            
            if (i >= m || i < 0 || j >= n || j < 0)
                cout << "detect i and j :" << i << " " << j << endl;
            if (i >= 0 && i < m && (j >= n || nums1[i] <= nums2[j]) && (j == 0 || nums2[j-1] <= nums1[i]))
                return nums1[i];
            else if (j >= 0 && j < n && (i >= m || nums2[j] <= nums1[i]) && (i == 0 || nums1[i-1] <= nums2[j]))
                return nums2[j];
            if (j >= n || nums1[i] < nums2[j]) l = i + 1;
            else r = i - 1;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m == 0 && n == 0)
            return 0;
        if (nums1.empty())
            return (nums2[(n-1)/2] + nums2[n/2])*0.5;
        if (nums2.empty())
            return (nums1[(m-1)/2] + nums1[m/2])*0.5;
        if ( (m + n) % 2 != 0) {
            return findKth(nums1, m, nums2, n, (m+n)/2 + 1);
        }
        else {
            int a = findKth(nums1, m, nums2, n, (m+n)/2);
            int b = findKth(nums1, m, nums2, n, (m+n)/2 + 1);
            
            cout << a << " " << b << endl;
            return (a+b)*0.5;
        }
        
    }
};
