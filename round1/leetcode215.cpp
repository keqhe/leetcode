
class Solution {
public:
    //option1, STL,sort (excise only)
    //option2, quickSort (excise only), avg: O(nlogn), worse:O(n^2), in place
    //option3, mergeSort (excise only) , avg:O(nlogn), worst:O(nlogn), extra space needed
    //option4, headSort (new learn), avg:O(nlogn), worst:O(nlog), in place
    //option5, quickSelect (new learn)
    
    
    void printVector(vector<int>&nums) {
        for (int i = 0; i < nums.size(); i ++) {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(), nums.end());
        //quickSort(nums, 0, nums.size() - 1);
        //mergeSort(nums, 0, nums.size() - 1);
        //heapSort(nums);//this is a max heap
        //printVector(nums);
        //std::reverse(nums.begin(), nums.end());//complexity O(n/2)
        //return nums[k-1];
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    
    
    //------quickSelect
    int swap(int &val1, int&val2) {
        int tmp = val1;
        val1 = val2;
        val2 = tmp;
    }
    int partition2(vector<int> &nums, int left, int right) {//this partition method seems to be easier to understand
    //and the returned index points to element with value of pivot
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j ++) {
            if (nums[j] >= pivot) {
                i ++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i + 1;//with value of pivot
    }
    
    int quickSelect(vector<int> & nums, int left, int right, int k) {
        if (left == right)
            return nums[left];
        int p = partition2(nums, left, right);
        if (k - 1 == p)
            return nums[p];
        else if (k - 1 < p)
            return quickSelect(nums, left, p - 1, k);
        else
            return quickSelect(nums, p + 1, right, k);
    }
    //-----------heap sort
    int parent(int i) {
        return i/2;
    }
    int left(int i) {
        return 2*i + 1;//index from 0
    }
    int right(int i) {
        return 2*i + 2;//index from 0
    }
    void maxHeapify(vector<int>&nums, int i, int len) {
        int l = left(i);
        int r = right(i);
        int largest;
        if(l < len && nums[l] > nums[i])
            largest = l;
        else
            largest = i;
        if (r < len && nums[r] > nums[largest])
            largest = r;
        if (largest != i) {
            int t = nums[i];
            nums[i] = nums[largest];
            nums[largest] = t;
            maxHeapify(nums, largest, len);
        }
    }
    
    void buildHeap(vector<int>& nums) {
        int len = nums.size();
        for (int i = len/2; i >= 0; i--) {//len/2 is the first leaf
            maxHeapify(nums, i, len);
        }
    }
    void heapSort(vector<int>& nums) {
        buildHeap(nums);
        int len = nums.size();
        for (int i = len -1; i >= 1; i --) {//from the last to the second
            int t = nums[0];
            nums[0] = nums[i];
            nums[i] = t;
            len --;
            maxHeapify(nums, 0, len);
        }
    }
    //-----------merge sort 
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;//think about left:0 and right:1
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> t1(n1, 0);
        vector<int> t2(n2, 0);
        
        for (int i = 0; i < n1; i ++)
            t1[i] = nums[left+i];
        for (int j = 0; j < n2; j ++)
            t2[j] = nums[mid+j+1];
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (t1[i] >= t2[j]) {
                nums[k] = t1[i];
                i ++;
                k ++;
            }
            else {
                nums[k] = t2[j];
                j ++;
                k ++;
            }
        }
        
        while(i < n1) {
            nums[k ++] = t1[i ++];
        }
        
        while(j < n2) {
            nums[k ++] = t2[j ++];
        }
    }
    
    //------------------------------------------------------------------------------------------
    //just an excise for quickSort below
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int t = partition(nums, left, right);
            quickSort(nums, left, t - 1);
            quickSort(nums, t, right);
        }
    }
    //[1,3,2], left = 0, right = 2
    //mid = 1; x = 3
    //Loop 0: i = 0, j = 2;  i = 0; j = 1; i <= j; [3, 1, 2]; i = 1, j = 0; 
    //partition return i (which is 1), so we have quickSort(nums, 0, 0) and quickSort(1, 2); quickSort(nums, 0, 0) terminates
    //so let's see quickSort(1, 2)
    //mid = (1+2)/2 = 1, x = 1; i = 1, j = 2;
    //Loop 0: i = 1, j = 2; i = 1, j = 2; [3, 2, 1]; i = 2, j = 1;
    //parition return i (which is 2)
    //no quickSort call is further called...
    
    //key idea of partition: all the elements in range [left, i) are larger or equal x, 
    
    int partition(vector<int> & nums, int left, int right) {
        
        int mid = left + (right - left) / 2;
        int x = nums[mid];
        int i = left;
        int j = right;
        while(i <= j) {
            while (nums[i] > x) {
                i ++;
            }
            while (nums[j] < x) {
                j --;
            }
            if (i <= j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i ++;
                j --;
            }
        }
        return i;
    }
};
