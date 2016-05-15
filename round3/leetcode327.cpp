
//idea is to count while doing merge sort so time compleixty is O(nlogn)
class Solution {
public:
    //naive method check every possible range
    int countRangeSum_naive_TLE(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower > upper)
            return 0;
        int sz = nums.size();
        vector<int> sums(sz+1, 0);//sums[i] is the sum of range nums[0..i-1]
        for (int i = 1; i <= nums.size(); i ++)
            sums[i] = sums[i-1] + nums[i];
        int count = 0;
        for (int i = 0; i < sums.size(); i ++) {
            for (int j = i+1; j < sums.size(); j ++) {
                //sums[j] - sums[i] = sum of nums[i..j-1]
                if (sums[j] - sums[i] >= lower && sums[j] - sums[i] <= upper)
                    count ++;
            }
        }
        return count;
    }
    //sums are already sorted so we do not care the sorting at all, what we need to care is
    //for any i, we need to find all possible j's such as sums[j]-sums[i]>=lower and sums[j]-sums[i]<=upper
    int mergeCount(vector<long>&sums, int l, int r, int lower, int upper) {
        if (l >= r)
            return 0;
        int mid = l + (r - l)/2;
        int count = mergeCount(sums, l, mid, lower, upper) + mergeCount(sums, mid+1, r, lower, upper);
        vector<long> tmp(r-l+1);
        int i = l;
        int j = mid+1;
        int k = 0;
        int j1 = mid+1;//the initilization of j1 and j2
        int j2 = mid+1;
        while (i <= mid) {
            while (j1 <= r && (sums[j1]-sums[i]) < lower)
                j1 ++;
            while (j2 <= r && (sums[j2]-sums[i]) <= upper)
                j2 ++;
            count += j2-j1;
            while (j <= r && sums[j] < sums[i]) {
                tmp[k++] = sums[j++];
            }
            tmp[k++] = sums[i++];
        }
        while (j <= r) 
            tmp[k++] = sums[j++];
        for (int x = l; x <= r; x ++)
            sums[x] = tmp[x-l];
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower > upper)
            return 0;
        int sz = nums.size();
        vector<long> sums(sz+1, 0);
        for (int i = 1; i <= nums.size(); i ++)
            sums[i] = sums[i-1] + nums[i-1];
        int count = mergeCount(sums, 0, sums.size()-1, lower, upper);
        return count;
    }
};

