
class Solution {
public:
    //target: O(nlogn)
    int merge(vector<long> &sum, int l, int m, int r, int lower, int upper) {
        vector<long> tmp(r-l+1);
        int i = l;
        int j = m+1;
        int k = 0;
        int count = 0;
        /*while (i <= m && j <= r) {
            long gap = sum[j] - sum[i];
            if (gap >= lower && gap <= upper)
                count ++;
            if (sum[i] <= sum[j]) {
                tmp[k++] = sum[i++];
            }
            else {
                cout << "impossible" << endl;
                tmp[k++] = sum[j++];
            }
        }
        while (i <= m) {
            long gap = sum[j-1] - sum[i];
            if (gap >= lower && gap <= upper)
                count ++;
            tmp[k++] = sum[i++];
        }
        while (j <= r) {
            long gap = sum[j] - sum[i-1];
            if (gap >= lower && gap <= upper)
                count ++;
            tmp[k++] = sum[j++];
        }*/
        
        int j1 = m+1;
        int j2 = m+1;
        while (i <= m) {
            while (j1 <= r && (sum[j1]-sum[i]) < lower)
                j1 ++;
            while (j2 <= r && (sum[j2]-sum[i]) <= upper)
                j2 ++;
            count += j2 - j1;
            while (j <= r && sum[j] < sum[i]) {
                tmp[k++] = sum[j++];
            }
            tmp[k++] = sum[i++];
        }
        while (j <= r) {
            tmp[k++] = sum[j++];
        }
        for (int p = l; p <= r; p ++) {
            sum[p] = tmp[p-l];
        }
        return count;
    }
    int mergeSort(vector<long>&sum, int l, int r, int lower, int upper) {
        if (l >= r)
            return 0;
        else {
            int mid = l + (r-l)/2;
            int a = mergeSort(sum, l, mid, lower, upper);
            int b = mergeSort(sum, mid+1, r, lower, upper);
            int c = merge(sum, l, mid, r, lower, upper);
            return a + b + c;
        }
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower > upper)
            return 0;
        int size = nums.size();
        //sum[i] represents the sum for range[0..i-1]
        vector<long> sum(size+1, 0);
        for (int i = 0; i < nums.size(); i ++) {
            sum[i+1] = sum[i] + nums[i];
        }
        for (int i = 0; i < sum.size(); i ++)
            cout << sum[i] << endl;
        return mergeSort(sum, 0, sum.size()-1, lower, upper);
    }
};
