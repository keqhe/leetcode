
class Solution {
public:
    //ref: https://leetcode.com/discuss/65886/concise-java-dp-solution-with-comments
    //let dp[i][j] denotes the edit distance between word1[0...i-1] and word2[0...j-1]
    //so when word1[i-1] == word2[j-1], dp[i][j] = dp[i-1][j-1]
    //else   dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j])) + 1;
    int minDistance(string word1, string word2) {
        if (word1.empty())
            return word2.length();
        if (word2.empty())
            return word1.length();
        vector<vector<int>> dp (word1.length()+1, vector<int>(word2.length()+1, 0));
        for (int i = 0; i <= word1.length(); i ++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.length(); j ++)
            dp[0][j] = j;
        cout << "debug" << endl;
        for (int i = 1; i <= word1.length(); i ++) {
            for (int j = 1; j <= word2.length(); j ++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        
        return dp[word1.length()][word2.length()];
    }
};
