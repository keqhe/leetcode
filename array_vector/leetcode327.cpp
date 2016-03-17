class Solution {
public:
    //first naive solution, denote sums[j] - sums[i] of the sum of range [i,j)
    //though it is TLE, but the logic is clear and correct
    int countRangeSum_naive(vector<int>& nums, int lower, int upper) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        vector<int> sums(len+1, 0);
        for (int i = 0; i < nums.size(); i ++) {
            sums[i+1] = nums[i] + sums[i];
        }
        int total = 0;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j <= nums.size(); j ++) {
                if (sums[j] - sums[i] >= lower && sums[j] - sums[i] <= upper)
                    total ++;
            }
        }
        return total;
    }
    //merge sort-based
    //for i, we want to get the number of j's that satisfy lower <= sums[j] - sums[i] <= upper, where i < j;
    int mergeCount(vector<long> & nums, int left, int right, int lower, int upper) {
        //why == also return 0? think why, i think because the definition of sums array
        if (left >= right) 
            return 0;
        int mid = left + (right - left)/2;
        int count = mergeCount(nums, left, mid, lower, upper) + mergeCount(nums, mid+1, right, lower, upper);
        vector<int> mergedArr(right-left+1, 0);
        int j = mid+1;
        int i = left;
        int k = 0;
        int i1 = mid+1;
        int i2 = mid+1;
        
        while (i <= mid) {
            while (i1 <= right && nums[i1] - nums[i] < lower)
                i1 ++;
            while (i2 <= right && nums[i2] - nums[i] <= upper)
                i2 ++;
            count += i2 - i1;
            while (j <= right && nums[j] < nums[i])
                mergedArr[k++] = nums[j++];
            mergedArr[k++] = nums[i++];
        }
        while (j <= right)
            mergedArr[k++] = nums[j++];
        for (int t = left; t <= right; t ++)
            nums[t] = mergedArr[t-left];
        return count;
    }
    int mergeSortCounting(vector<long> & tmp, int left, int right, int lower, int higher) {
        if (left >= right) return 0;
        int mid = left + (right - left)/2;
        int count = mergeSortCounting(tmp, left, mid, lower, higher) + mergeSortCounting(tmp, mid+1, right, lower, higher);
        vector<long> mergedArr(right-left+1, 0);
        int i = left;
        int j = mid + 1;
        int k = 0;
        int index1 = mid + 1;//
        int index2 = mid + 1;
        while (i <= mid) {
            while (index1 <= right && tmp[index1] - tmp[i] < lower) index1 ++;
            while (index2 <= right && tmp[index2] - tmp[i] <= higher) index2 ++;
            //at this point tmp[index2] - tmp[i] > higher && tmp[index1] - tmp[i] >= lower
            count += index2 - index1;
            
            while (j <= right && tmp[j] < tmp[i])
                mergedArr[k++] = tmp[j++];
            mergedArr[k++] = tmp[i++];
        }
        while (j <= right)
            mergedArr[k++] = tmp[j++];
        for (int t = left; t <= right; t ++) {
            tmp[t] = mergedArr[t-left];
        }
        return count;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        vector<long> sums(len+1, 0);
        for (int i = 0; i < nums.size(); i ++) {
            sums[i+1] = nums[i] + sums[i];
        }
        int count = mergeCount(sums, 0, sums.size()-1, lower, upper);
        return count;
    }
};

//ref:
class Solution__ {
public:
    //ref: https://leetcode.com/discuss/79083/share-my-solution
    //the idea is merge sort while couting
    //ref: this blog is easier to understand: https://leetcode.com/discuss/79907/summary-divide-conquer-based-binary-indexed-based-solutions
    int mergeSortCounting(vector<long> & tmp, int left, int right, int lower, int higher) {
        if (left >= right) return 0;
        int mid = left + (right - left)/2;
        int count = mergeSortCounting(tmp, left, mid, lower, higher) + mergeSortCounting(tmp, mid+1, right, lower, higher);
        vector<long> mergedArr(right-left+1, 0);
        int i = left;
        int j = mid + 1;
        int k = 0;
        int index1 = mid + 1;//
        int index2 = mid + 1;
        while (i <= mid) {
            while (index1 <= right && tmp[index1] - tmp[i] < lower) index1 ++;
            while (index2 <= right && tmp[index2] - tmp[i] <= higher) index2 ++;
            //at this point tmp[index2] - tmp[i] > higher && tmp[index1] - tmp[i] >= lower
            count += index2 - index1;
            
            while (j <= right && tmp[j] < tmp[i])
                mergedArr[k++] = tmp[j++];
            mergedArr[k++] = tmp[i++];
        }
        while (j <= right)
            mergedArr[k++] = tmp[j++];
        for (int t = left; t <= right; t ++) {
            tmp[t] = mergedArr[t-left];
        }
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower > upper)
            return 0;
        vector<long> tmp(nums.size()+1, 0);//index are from 0 to nums.size()
        for (int i = 0; i < nums.size(); i ++)
            tmp[i+1] = tmp[i] + nums[i];
        int count = mergeSortCounting(tmp, 0, tmp.size()-1, lower, upper);
        return count;
    }
    
    //BST, see https://leetcode.com/discuss/79632/multiset-solution-100ms-binary-search-tree-180ms-mergesort
    int countRangeSum__bst(vector<int>& nums, int lower, int upper) {
        if (nums.empty())
            return 0;
        vector<long> sums(nums.size()+1, 0);
        
        // the sum of nums[i,...j] == sums[j+1] - sums[i] where j >= i;
        //low <= sums[j+1] - sums[i] <= high
        multiset<long> mt;
        int res = 0;
        mt.insert(0);
        for (int i = 1; i < sums.size(); i ++) {
             //mt.insert(sums[i]); WHy not here? when we processing sums[i], we want to find all j (j < j) such that sums[i] - sums[j] is between [lower, upper] 
             sums[i] = sums[i-1] + nums[i];
             long low = sums[i] - upper;
             long high = sums[i] - lower;
             
             multiset<long>::iterator it_low = mt.lower_bound(low);
             multiset<long>::iterator it_high = mt.upper_bound(high);
             res += distance(it_low, it_high);//time complexity is O(N)
             mt.insert(sums[i]);
        }
        cout << res << endl;
        return res;
    }
    
    /*naive solution, O(n^2)*/
    /*
    int __countRangeSum__naive(vector<int>& nums, int lower, int upper) {
        if (nums.empty())
            return 0;
        vector<long> sums(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i ++) {//the data struct is very cute, think about the case
        //where nums=[-2, 5, -1], then, sums = [0, -2, 3, 2]
            sums[i+1] = sums[i] + nums[i];
        }
        //note, sums[j] - sums[i] is the sum of range nums [i, j), j > i
        int total = 0;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; i <= nums.size(); j ++) {
                if (sums[j] - sums[i] >= lower && sums[j] - sums[i] <= upper)   
                    total += 1;
            }
        }
        
        return total;
    }
    */
};
