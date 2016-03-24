
class Solution {
public:
    //ref: https://leetcode.com/discuss/61652/simple-o-n-java-solution-with-comments
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        if (ratings.size() == 1)
            return 1;
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < candies.size(); i ++) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        
        for (int i = candies.size()-2; i >= 0; i --) {
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        }
        
        int sum = 0;
        for (auto x : candies)
            sum += x;
        return sum;
    }
};
