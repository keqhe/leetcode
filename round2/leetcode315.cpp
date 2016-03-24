
struct Node {
    int val;
    int index;
    Node() {
        this->val = 0;
        this->index = 0;
    }
    Node(int v, int idx) {
        val = v;
        index = idx;
    }
    Node &operator=(const struct Node & n) {
        this->val = n.val;
        this->index = n.index;
    }
    bool operator <(const struct Node & n) {
        return val < n.val;
    }
};

class Solution {
public:
    //https://leetcode.com/discuss/73256/mergesort-solution
    void merge(vector<struct Node> & nums, int left, int mid, int right, vector<int>&res) {
        vector<struct Node> tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        int count = 0;
        while (i <= mid) {
            while (j <= right && nums[j] < nums[i]) {
                count ++;
                tmp[k++] = nums[j++];
            }        
            tmp[k++] = nums[i];
            res[nums[i].index] += count;
            i ++;
        }
        while (j <= right)
            tmp[k++] = nums[j++];
        for (int t = left; t <= right; t ++)
            nums[t] = tmp[t-left];
    }
    void mergeSort(vector<struct Node> & nums, int left, int right, vector<int>&res) {
        if (left < right) {
            int mid = left + (right - left)/2;
            mergeSort(nums, left, mid, res);
            mergeSort(nums, mid+1, right, res);
            merge(nums, left, mid, right, res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        res.resize(nums.size(), 0);
        vector<struct Node> nodeArr;
        for (int i = 0; i < nums.size(); i ++) {
            struct Node n (nums[i], i);
            nodeArr.push_back(n);
        }
        for (int i = 0; i < nodeArr.size(); i ++) {
            cout << nodeArr[i].index << " " << nodeArr[i].val << endl;
        }
        mergeSort(nodeArr, 0, nodeArr.size()-1, res);
        return res;
    }
};

/*
//ref in round 1
class Solution__ {
public:
    //merge sort, or BST or Binary Indexed Tree (BIT)
    struct Node {
        int val;
        int index;
        Node() {
            val = 0;
            index = 0;
        }
        Node (int val, int index) {
            this->val = val;
            this->index = index;
        }
        Node & operator=(const struct Node & n2) {
            this->val = n2.val;
            this->index = n2.index;
        }  
        bool operator < (const struct Node & n2) {
            return val < n2.val;
        }
        
    };
    
    void merge(vector<struct Node> & arr, int left, int mid, int right, vector<int> & counts) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<struct Node> l (n1);
        vector<struct Node> r (n2);
        //cout << "merge called:" << left << " " << mid << " " << right << endl;
        for (int i = 0; i < n1; i ++) {
            l[i] = arr[left+i];
            //cout << "l arr: " << i << " " << l[i].val << " " << l[i].index << " ";
        }
        //cout << endl;
        for (int i = 0; i < n2; i ++) {
            r[i] = arr[mid+1+i];
            //cout << "r arr: " << i << " " << r[i].val << " " << r[i].index << " ";
        }
        //cout << endl;
        
        int i = 0;
        int j = 0;
        int k = left;
        int rightCount = 0;
        
        while (i < n1 && j < n2) {
            if (l[i] <= r[j]) {
                arr[k] = l[i];
                
                
                counts[l[i].index] += rightCount;// pay attention
                /*if (rightCount > 0) {
                cout << "change counts array.. " << i << " " << l[i].val << " " << l[i].index << " " << counts[l[i].index] << endl;
                }*/
            /*   
                i ++;
            }
            else {//pick from right side
                arr[k] = r[j];
                
                //cout << "k:" << k << " pick from right half..." << endl;
                rightCount ++;//pay attention
                //cout << "k:" << k << " right count is:" << rightCount << endl;
                j ++;
            }
            k ++;
        }
        while (i < n1) {
            arr[k] = l[i];
            //cout << "change counts array.. " << l[i].index << " " << counts[l[i].index] << endl;
            counts[l[i].index] += rightCount;// pay attention
            
            i ++;
            k ++;
        }
        while (j < n2) {
            arr[k] = r[j];
            j ++;
            k ++;
        }
    }
    void mergeSort(vector<struct Node> & arr, int left, int right, vector<int> & counts) {
        if (left < right) {
            int mid = left + (right - left)/2;
            mergeSort(arr, left, mid, counts);
            mergeSort(arr, mid+1, right, counts);
            merge(arr, left, mid, right, counts);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<int>();
        if (nums.size() == 1) {
            return vector<int>(1);
        }
        vector<struct Node> arr;
        for (int i = 0; i < nums.size(); i ++) {
            struct Node tmp (nums[i], i);
            arr.push_back(tmp);
        }
        vector<int> counts(nums.size(), 0);
        mergeSort(arr, 0, nums.size() - 1, counts);
        
        
        return counts;
    }
};
*/
