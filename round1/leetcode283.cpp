
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            //cout <<"process " << i << " that is " << nums[i]<<endl;
            //printVector(nums);
            if (nums[i] == 0) {
                //cout << "process i is " << nums[i] << ' ';
                for (int j = i + 1; j < nums.size(); j ++) {
                    if (nums[j] != 0) {
                        //cout << "swap " << nums[i] <<" and "<< nums[j]<<endl;
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
            }
        }
    }
};
