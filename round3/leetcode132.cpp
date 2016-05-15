
class Solution {
public:
    //let pal[i][j] denote whether s[i..j] is palindrome
    /*
    */
    int minCut(string s) {
      if (s.empty() || s.length() == 1)
        return 0;
      int len = s.length();
      vector<vector<bool>> pal (len, vector<bool>(len, false));
      //for substring of length 1 and 2
      for (int i = 0; i < len; i ++) {
          pal[i][i] = true;
          if (i+1 < len && s[i] == s[i+1])
            pal[i][i+1] = true;
      }
      //for substring of length >= 3
      for (int l = 3; l <= len; l ++) {
          for (int i = 0; i < len; i ++) {
            int j = i + l - 1;
            if (j >= len || j < 0)
                continue;
            if (s[i] == s[j] && pal[i+1][j-1])
                pal[i][j] = true;
          }
      }
      //let dp[i] denote the min cut of substring [0...i]
      //dp[i] = min(dp[j-1] + 1) for all 0 <= j <= i
      vector<int> dp(len, len);
      for (int i = 0; i < len; i ++) {
          int curr_min = numeric_limits<int>::max();
          for (int j = 0; j <= i; j ++) {
              if (pal[j][i]) {
                if (j == 0)
                    curr_min = 0;
                else
                    curr_min = min(curr_min, dp[j-1]+1);
              }
          }
          dp[i] = curr_min;
      }
      return dp[len-1];
    }
};
