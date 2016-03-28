
#include <iostream>
using namespace std;


//mem
int fab_method(int n, unordered_map<int, int> & m) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  if (m.find(n) != m.end())
    return m[n];
  
  int res = fab(n-1) + fab(n-2);
  m[n] = res;
  return res;
}

//dp[i] = dp[i-1] + dp[i-2]
int fab_method2(int n) {
  vector<int> dp(n+1, 0);
  dp[1] = 1;
  dp[2] = 2;
  
  for (int i = 3; i <=n; i ++)
      dp[i] = dp[i-1] + dp[i-2];
  return dp[n];
}

//let dp[i] denotes the length of LIS which ends at nums[i]
//then dp[i] = max(dp[j] + 1) && num[i] > num[j] where 0<= j < i;

class Solution {
public:
    //let dp[i] denotes
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
          return 0;
        vector<int> dp(nums.size(), 1); //?
        int maxLen = 1;
        for (int i = 0; i < nums.size(); i ++) {
          for (int j = 0; j < i; j ++) {
            if (nums[i] > nums[j]) {
              if (dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
              //dp[i] = max(dp[i], dp[j]+1);
            }
          }
        }
        for (int i = 0; i < nums.size(); i ++
            maxLen = max(maxLen, dp[i]);
        return maxLen;
    }
};
             
//[1,2,5], amount=3
////let dp[i] denote the fewest number coins for money amount of i
//dp[i] = min(dp[i], dp[j]+1), (i-j) should be the coin array

//vector<int> (amount, numeric_limits<int>::max());
//dp[j] = 1, where j appears in the coin array
//dp[..] = {1,1,$}

class Solution {
public:
    //[1,2,5], amount=3
  ////let dp[i] denote the fewest number coins for money amount of i
//dp[i] = min(dp[i], dp[j]+1), (i-j) should be the coin array

//vector<int> (amount, numeric_limits<int>::max());
//dp[j] = 1, where j appears in the coin array
//dp[..] = {1,1,$}
                                                                                    
    }
};

//s1 = "ABCDE"
//s2 = "BUDF";
//LCS = "BD"
//let dp[i][i] the length of LCS for s1[0..i-1] and s2[0..j-1]
//dp[i][j] = dp[i-1][j-1] + 1 iff s1[i-1] == s2[j-1]
//what if s1[i-1] != s2[j-1], max(dp[i-1][j], dp[i][j-1])

//dp[0][0] = 0

//p q r , for example, (2 4) (4 3) (3 7)
//[2 4 3 7], if there are n matrix, then input is an n+1-sized array
      

//dp[i][j] denote the number of operations needed for array [i, j]
//dp[0][3] = dp[0][2] + dp[3][3] + 2*3*7, when k = 2;
//dp[i][j] = min(dp[i][k]+dp[k+1][j] + nums[i-1]*num[k]*num[j]), i <=k < j 
             
// To execute C++, please define "int main()"
int main() {
  
  return 0;
}

/* 
Your previous Plain Text content is preserved below:


 */
