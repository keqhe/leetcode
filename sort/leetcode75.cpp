class Solution {
public:
    //first method is counting sort
    void sortColors_coutingSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int k = 0;
        for (auto x : nums) {
            k = max(k, x);
        }
        //count[j] stores the number of elements that are <= j
        vector<int> count(k+1, 0);
        for (int i = 0; i < nums.size(); i ++) {
            count[nums[i]] ++;
        }
        for (int i = 1; i < count.size(); i ++) {
            count[i] = count[i] + count[i-1];
        }
        
        vector<int> B (nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; i --) {//back to front, notice the order
            int val = nums[i];
            int pos = --count[val];//because index starts from 0
            B[pos] = val;
        }
        nums = B;
    }
    //method 2:  the basic idea is to use two pointer low and high and an iterator i, every elem left low pointer is 0, elem right high pointer is 2
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int low = 0;
        int high = nums.size()-1;
        int i=low;
        while (i <= high) {
            if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                i ++;
                low ++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[high]);
                high --;
            }
            else
                i ++;
        }
    }
};
