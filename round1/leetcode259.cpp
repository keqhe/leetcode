
public:
    //ref: https://leetcode.com/discuss/63016/accepted-and-simple-java-solution-with-detailed-explanation
    //version 1
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.empty())   
            return 0;
        int total = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                if (nums[i] + nums[low] + nums[high] < target) {
                    total += high - low;
                    low ++;
                }
                else {
                    high --;
                }
            }
        }
        return total;
    }
    /*
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int total = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                for (int k = nums.size()-1; k > j; k --) {
                    if (nums[i] + nums[j] + nums[k] < target) {
                        //cout << i << " " << j << " " << k << endl;
                        total += k - j;
                        break;
                    }
                }
            }
        }
        return total;
    }*/
};
