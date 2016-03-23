
class Solution {
public:
    //afet finishhing subset II, i am doing it again
    void newhelper(vector<int> & nums, int start, vector<int> & inst, vector<vector<int>> & res) {
        for (int i = start; i < nums.size(); i ++) {
            inst.push_back(nums[i]);
            res.push_back(inst);
            newhelper(nums, i+1, inst, res);
            inst.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> & nums) {
        vector<int> inst;
        vector<vector<int>> res;
        res.push_back(inst);
        sort(nums.begin(), nums.end());
        newhelper(nums, 0, inst, res);
        return res;
    }
    
    //old stuff
    vector<vector<int>> helper(vector<int>& nums, int index) {
        vector<vector<int>> res;
        if (index == -1) {
            vector<int> e;
            res.push_back(e);
            return res;
        }
        
        res = helper(nums, index-1);
        int size = res.size();
        //for (int i = 0; i < res.size(); i ++) {//critical error, you are res.size() is CHANGING!!!
        for (int i = 0; i < size; i ++) {
            vector<int> t = res[i];
            t.push_back(nums[index]);
            res.push_back(t);
        }
        
        return res;
    }
    //[0, 2, 3]
    //index==-1:[]
    //index==0: [] [0]
    //index==1: [] [0] [2] [0,2]
    //index==2: [] [0] [2] [0,2] [3] [0,3] [2,3] [0,2,3]
    vector<vector<int>> subsets_recur(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        return helper(nums, nums.size() - 1);
    }
    
    vector<vector<int>> subsets_3(vector<int> & nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        vector<int> v;
        res.push_back(v);
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            int sz2 = res.size();
            for(int j = 0; j < sz2; j ++) {
                vector<int> t = res[j];
                t.push_back(nums[i]);
                res.push_back(t);
            }
        }
        return res;
    }
    
    //my initial thought: sort integers in nums array, then output subsets with length 0, 1,...n where n is array.size()
    //hmm, this is WRONG, e.g., [0, 1, 3], i will miss subset [0, 3]...
    
};
