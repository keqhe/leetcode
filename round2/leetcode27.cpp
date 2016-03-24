
class Solution {
public:
    //[2], val = 2
    //[1, 2], val = 2
    //[1, 2, 2, 4, 5, 5], val = 2
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                nums[i++] = nums[j++];
            }
            else
                j ++;
        }
        cout << i << endl;
        return i;
    }
};
