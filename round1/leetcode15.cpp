
class Solution {
public:
    //the first thought is to use backtracking
    //then see, this reference: http://www.programcreek.com/2012/12/leetcode-3sum/
    //time complexity is O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i-1])//avoid duplicates
                continue;
            //cout << "i is ..." << i << endl;
            int curr = nums[i];
            int left = i + 1;
            int right = nums.size()-1;
            while (left < right) {
                if (nums[left] + nums[right] + curr == 0) {
                    //cout << "debug..." << endl;
                    vector<int> inst;
                    inst.push_back(curr);
                    inst.push_back(nums[left]);
                    inst.push_back(nums[right]);
                    res.push_back(inst);
                    
                    left ++;
                    right --;
                    while (left < right && nums[left] == nums[left-1])
                        left ++;
                    while (left < right && nums[right] == nums[right+1])
                        right --;
                }
                else if (nums[left] + nums[right] + curr < 0) {
                    //cout << "debug2..." << endl;
                    left ++;
                }
                else {
                    //cout << "debug3..." << endl;
                    right --;
                }
            }
        }
        
        return res;
    }
};
