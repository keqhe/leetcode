
class Solution {
public:
    //O(N) idea:
    /*
    We can always assign a neighbor with 1 more if the neighbor has higher a rating value. However, to get the minimum total number, we should always start adding 1s in the ascending order. We can solve this problem by scanning the array from both sides. First, scan the array from left to right, and assign values for all the ascending pairs. Then scan from right to left and assign values to descending pairs. 
    */
    //of course, you can sort it (O(NlogN)) and increase candy 1 by 1
    //example rating array: 1, 4, 10, 5, 0
    //[1, 4, 10, 15, 5, 0]
    //[1, 2, 3,  4,  1, 1] ; from left to right scan
    // 1   2     3     3    2    1
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        }
        
        for (int i = ratings.size() - 2; i >= 0; i --) {
            if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
                candy[i] = candy[i+1] + 1;
        }
        
        int res = 0;
        for (auto & x: candy)
            res += x;
        return res;
    }   
};
