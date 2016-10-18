class Solution {
public:
    /* this first solution is to use hash tables, quite simple
    unordered_map<int, vector<int>> m;
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i ++) {
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = m[target].size();
        int x = rand() % size;
        return m[target][x];
    }*/
    
    //second method is reservoir sampling
    vector<int> copy;
    Solution(vector<int> nums) {
        copy = nums;
    }
    
    int pick(int target) {
        int res = -1;
        int count = 0;
        for (int i = 0; i < copy.size(); i ++) {
            if (copy[i] != target)
                continue;
            count ++;
            int r = rand() % count;
            if (r == 0) {
                res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
