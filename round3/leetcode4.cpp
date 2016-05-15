
class Solution {
public:
    //using two pointers, this problem can be solved in O(m+n)
    
    //if we only allowed O(m+n) time complexity, 
    //we use the routine to get the Kth element in the unoin of two sorted arraies
    
    //we want to find the kth element in the union of nums1 and nums2
    int findKth(vector<int>&nums1, int m, vector<int>&nums2, int n, int k) {
        //we use i denote the possible index of nums1, which should be in range [0..m]
        //we use j denote the possible index of nums2, which should be in range [0...n] , think why including n
        //i + j = k - 1, when i = 0, j = k-1, when i = k, j = -1
        //now we try to bound i, using l and r
    
        //for the following case, think about the case where n == 0
        int l = k-1 - min(k-1, n);//l determines the left boundary of i (inclusive)
        int r = min(k, m);//r determines the right boundary of i (exclusive)
        
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = k-1-i;
            //the following, think about j == 0 and i == k-1, nums1[i] is the kth element
            if (i >= 0 && i <= m-1 && 
                ((j == n || nums1[i] <= nums2[j]) && (j == 0 || nums2[j-1] <= nums1[i])))
                return nums1[i];
            if (j >= 0 && j <=n-1 && 
                ((i == m || nums2[j] <= nums1[i]) && (i == 0 || nums1[i-1] <= nums2[j])))
                return nums2[j];
            if (j >= n || nums1[i] < nums2[j])
                l = i + 1;
            else
                r = i - 1;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if ((m + n) & 1) {//odd, 1,2,3,4,5
            return findKth(nums1, m, nums2, n, (m+n)/2+1);//note, Kth
        }
        else {//1,2,3,4
            int a = findKth(nums1, m, nums2, n, (m+n)/2);
            int b = findKth(nums1, m, nums2, n, (m+n)/2+1);
            //return (a+b)/2;//this is wrong because 5/2 == 2...
            return 0.5*(a+b);
        }
    }
};
