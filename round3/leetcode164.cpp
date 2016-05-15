
class Solution {
public:
    //couting sort here is not very suitable because the maximal number can be really large, counting sort is stuiable it k is well bounded (k is small)
    int maximumGap_coutingSort(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        long max_val = numeric_limits<long>::min();
        long min_val = numeric_limits<long>::max();
        
        for (auto x : nums) {
            max_val = max(max_val, (long)x);
            min_val = min(min_val, (long)x);
        }
        
        vector<int> cnt(max_val-min_val+1, 0);
        
        for (auto x : nums) {
            cnt[x-min_val] ++;
        }
        
        for (int i = 1; i < cnt.size(); i ++) {
            cnt[i] += cnt[i-1];
        }
        
        vector<int> B(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; i --) {
            int val = nums[i];
            int index = --cnt[val-min_val];
            B[index] = val;
        }
        
        int maxGap = 0;
        for (int i = 1; i < B.size(); i ++) {
            if (B[i]-B[i-1] > maxGap)
                maxGap = B[i]-B[i-1];
        }
        return maxGap;
    }
    
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        vector<vector<int>> tmp(nums.size(), vector<int>());
        
        int min_val = numeric_limits<int>::max();
        int max_val = numeric_limits<int>::min();
        for (auto x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        max_val ++;
        for (auto x : nums) {
            int index = nums.size()*((double) (x-min_val) / (double)(max_val-min_val));
            tmp[index].push_back(x);
        }
        
        for (int i = 0; i < tmp.size(); i ++) {
            sort(tmp[i].begin(), tmp[i].end());
        }
        
        int k = 0;
        for (int i = 0; i < tmp.size(); i ++) {
            for (int j = 0; j < tmp[i].size(); j ++)
                nums[k++] = tmp[i][j];
        }
        
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i]-nums[i-1] > maxGap)
                maxGap = nums[i]-nums[i-1];
        }
        return maxGap;
    }
};
