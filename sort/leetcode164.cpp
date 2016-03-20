
class Solution {
public:
    //ref: https://leetcode.com/discuss/80560/clean-c-implementation-based-on-radix-sort
    //ref: https://leetcode.com/discuss/80559/recommend-beginners-different-implementations-explaination
    //ref: https://leetcode.com/discuss/80559/recommend-beginners-different-implementations-explaination
    //couting sort(which I do not think quite suitable), radix sort (good fit) and bucket sort(good fit)
    void radixSort(vector<int> &nums) {
        if (nums.empty())
            return;
        int max_val = nums[0];
        for (auto x : nums) {
            if (x > max_val)
                max_val = x;
        }
        int base = 1;
        vector<int> B(nums.size());
        while (max_val / base > 0) {
            vector<int> counts(10, 0);//0- 9 for each digit
            for (int i = 0; i < nums.size(); i ++) {
                int front = nums[i] / base;
                int digit = front % 10;
                counts[digit] ++;
            }
            for (int i = 1; i < counts.size(); i ++)
                counts[i] = counts[i] + counts[i-1];
            for (int i = nums.size()-1; i >= 0; i --) {
                int front = nums[i] / base;
                int digit = front % 10;
                int pos = --counts[digit];
                B[pos] = nums[i];
            }
            
            for (int i = 0; i < nums.size(); i ++)
                nums[i] = B[i];
            base *= 10;
        }
    }
    void bucketSort(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int min_val = nums[0];
        int max_val = nums[0];
        for (auto x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        max_val ++; //in case max_val == min_val;
        int len = nums.size();
        vector<vector<int>> tmp(len, vector<int>());
        for (int i = 0; i < nums.size(); i ++) {
            int index = len*((double)(nums[i]-min_val)/(max_val-min_val));
            tmp[index].push_back(nums[i]);
        }
        for (int i = 0; i < tmp.size(); i ++)
            sort(tmp[i].begin(), tmp[i].end());
        int k = 0;
        for (int i = 0; i < tmp.size(); i ++) {
            for (int j = 0; j < tmp[i].size(); j ++) {
                nums[k++] = tmp[i][j];
            }
        }
    }
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        //radixSort(nums);
        bucketSort(nums);
        for (int i = 0; i < nums.size(); i ++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        int maxgap = 0;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] - nums[i-1] > maxgap)
                maxgap = nums[i] - nums[i-1];
        }
        return maxgap;
    }
};
