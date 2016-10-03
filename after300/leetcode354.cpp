
//mycmp is WRONG
bool mycmp(pair<int,int>&p1, pair<int, int>&p2) {
    return p1.first < p2.first;
}

bool myCmp(const pair<int, int> & p1, const pair<int, int> & p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}

class Solution {
public:
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myCmp);
        vector<int> tmp;
        for (auto x : envelopes) {
            tmp.push_back(x.second);
        }
        //dp[i] denote the length of LIS ending at index i
        vector<int> dp(tmp.size(), 1);
        for (int i = 1; i < tmp.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (tmp[i] > tmp[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int lis = 0;
        for (auto x : dp)
            lis = max(lis, x);
        return lis;
    }
};
