
class Solution {
public:
    //I made a mistake on vector index and its content initially
    void helper(vector<int> & nums, vector<int>  &tillnow, int & k, vector<vector<int>> & res) {
        if (tillnow.size() == k) {
            res.push_back(tillnow);
            return;
        }
        
        int last;
        if (tillnow.size() > 0)
            last = tillnow[tillnow.size()-1];
        else
            last = 0;//flag
            
        for (int i = last+1; i < nums.size(); i ++) {
            
            //vector<int> temp = tillnow;
            tillnow.push_back(nums[i]);
            //temp.push_back(nums[i]);
            helper(nums, tillnow, k, res);
            tillnow.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0 || k == 0)
            return res;
        vector<int> tillnow;
        vector<int> nums (n+1, 0);
        for (int i = 1; i <= n; i ++)
            nums[i] = i;
        helper(nums, tillnow, k, res);
        return res;
    }
};
