
class Solution {
public:
    //reference:A typical k-sum problem. Time is N to the power of (k-1).
    //http://www.programcreek.com/2013/02/leetcode-4sum-java/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        unordered_map<string, int> m;
        
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {//think about nums=[0,0,0,0] and target = 0;
                int left = j + 1;
                int right = nums.size() - 1;
                
                while (left < right) {
                    int now = nums[i] + nums[j] + nums[left] + nums[right];
                    if (now == target) {
                        string key = to_string(nums[i]) + "-" + to_string(nums[j]) + "-" + to_string(nums[left]) + "-" + to_string(nums[right]);
                        if (m.find(key) == m.end()) {//no exist
                            vector<int> inst;
                            inst.push_back(nums[i]);
                            inst.push_back(nums[j]);
                            inst.push_back(nums[left]);
                            inst.push_back(nums[right]);
                            res.push_back(inst);
                            
                            m[key] = 1;
                        }
                        else {
                            cout << "debug....key exist.." << endl;
                        }
                        
                        left ++;
                        right --;
                        while (left < right && nums[left] == nums[left-1])
                            left ++;
                        while (left < right && nums[right] == nums[right+1])
                            right --;
                    }
                    else if (now < target) {
                        left ++;
                    }
                    else 
                        right --;
                }
            }
        }
    }
};
