
class Solution {
public:
    //ref: http://shibaili.blogspot.com/2015/08/day-120-longest-increasing-subsequence.html
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> lis(len, 1);//lis[i] means the lenght of LIS ending with index i;
        
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < i; j ++) {
                if (lis[j] + 1 > lis[i] && nums[i] > nums[j])
                    lis[i] = lis[j] + 1;
            }
        }
        
        int m = 0;
        for (int i = 0; i < len; i ++) {
            if (lis[i] > m)
                m = lis[i];
        }
        return m;
    }
};
