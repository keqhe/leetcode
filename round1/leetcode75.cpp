
class Solution {
public:
    //couting sort
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return;
        int largest = nums[0];
        int smallest = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] < smallest)
                smallest = nums[i];
            if (nums[i] > largest)
                largest = nums[i];
        }
        
        int k = largest - smallest + 1;
        vector<int> count (k, 0);
        for (int i = 0; i < nums.size(); i ++) {
            count[nums[i]-smallest] += 1;
        }

        for (int i = 1; i < count.size(); i ++) {
            count[i] = count[i] + count[i-1];
        }
        vector<int> b (nums.size(), 0);
        //think about [1, 1, 2, 2] as an example
        for (int i = nums.size() - 1; i >= 0; i --) {
            int index = --count[nums[i]-smallest];
            b[index] = nums[i];
            cout << index << ' ' << nums[i] << endl;
        }
        nums = b;
    }
};
