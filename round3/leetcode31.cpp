
class Solution {
public:
    //1,3,2,5,4
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        int i = nums.size()-1;
        int j = -1;
        for (; i >= 1; i --) {
            if (nums[i] > nums[i-1]) {
                j = i - 1;
                break;
            }
        }
        if (j == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        else {
            int smallest = nums[j+1];
            int index = j + 1;
            for (int k = j+2; k < nums.size(); k ++) {
                if (smallest > nums[k] && nums[k] > nums[j]) {//this is important
                    smallest = nums[k];
                    index = k;
                }
            }
            cout << index << " " << j << endl;
            swap(nums[j], nums[index]);
            sort(nums.begin()+j+1, nums.end());
            return;
        }
        
    }
};
