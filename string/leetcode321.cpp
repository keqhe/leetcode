#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //ref:https://leetcode.com/discuss/85363/easy-to-understand-dp-c-implementation-but-with-tle
    //first use 3D dp 
    //dp[k][i][j] denotes the max number with length k and at most ending with nums1[i-1] and nums2[j-1]
    //dp[k][i][j] = max(dp[k-1][i-1][j]+to_string(nums1[i-1]), dp[k-1][i][j-1]+to_string(nums2[j-1])
    //        , dp[k][i-1][j-1])
    //when k == 0, dp[k][i][j] = 0
    
    //I found the index is important, error prone..
    
    string strMax(string s1, string s2) {
        while (s1.length() >= 1) {
            if (s1.front() == ' ')
                s1.erase(s1.begin());
            else
                break;
        }
        while (s2.length() >= 1) {
            if (s2.front() == ' ')
                s2.erase(s2.begin());
            else
                break;
        }
        
        if (s1.length() < s2.length())
            return s2;
        else if (s1.length() > s2.length())
            return s1;
        else {
            if (s1 >= s2)
                return s1;
            else    
                return s2;
        }
    }
    vector<int> maxNumber_3D_DP(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 + len2 < k)
            return res;//impossible to consutrct such a result
        vector<vector<vector<string>>> dp(k+1, vector<vector<string>>(len1+1, vector<string>(len2+1, "")));
        
        cout << strMax("123", "340") <<  endl;
        
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                dp[0][i][j] = "";//when k = 0
            }
        }
        for (int l = 1; l <= k; l ++) {
            dp[l][0][0] = ""; //take 0 digits from nums1 and nums2
        }
        for (int l = 1; l <= k; l ++) {
            for (int j = 1; j <= len2; j ++) {
                if (l <= j)
                    dp[l][0][j] = strMax(dp[l-1][0][j-1]+to_string(nums2[j-1]), dp[l-1][0][j-1]);//takes 0 digits from nums1
                else
                    dp[l][0][j] = "";
            }
        }
        for (int l = 1; l <= k; l ++) {
            for (int i = 1; i <= len1; i ++) {
                if (l <= i)
                    dp[l][i][0] = strMax(dp[l-1][i-1][0]+to_string(nums1[i-1]), dp[l-1][i-1][0]);//takes 0 digits from nums2
                else
                    dp[l][i][0] = "";
            }
        }
        for (int l = 1; l <= k; l ++) {
            for (int i = 1; i <= len1; i ++) {
                for (int j = 1; j <= len2; j ++) {
                    dp[l][i][j] = strMax(strMax(dp[l-1][i-1][j]+to_string(nums1[i-1]),
                                                dp[l-1][i][j-1]+to_string(nums2[j-1])),
                                         dp[l][i-1][j-1]);
                }
            }
        }
        string tmp = dp[k][len1][len2];
        for (auto c: tmp) {
            res.push_back(c-'0');
        }
        return res;
    }
    
    //ref: https://leetcode.com/discuss/85363/easy-to-understand-dp-c-implementation-but-with-tle?show=85363#q85363
    //the key idea is to find the max number with length i in each array first and merge them
    // and go through all the candidates to find the max number
    string helper_2D_DP(vector<int> & nums, int k) {
        string res;
        if (k == 0 || nums.empty())
            return res;
        int len = nums.size();
        vector<vector<string>> dp(k+1, vector<string>(nums.size()+1, ""));
        //dp[k][j] means the the max number we can get with len of k and ending at most at nums[j-1]
        //dp[k][j] = max(dp[k-1][j-1]+nums[j-1], dp[k][j-1])
        for (int i = 0; i <= len; i ++)
            dp[0][i] = "";
        for (int i = 1; i <= k; i ++)
            dp[i][0] = "";
        for (int i = 1; i <= k; i ++) {
            for (int j = 1; j <= len; j ++) {
                dp[i][j] = strMax(dp[i-1][j-1]+to_string(nums[j-1]), dp[i][j-1]);
            }
        }
        
        return dp[k][len];
    }
    string helper_2D_DP_lessSpace(vector<int> & nums, int k) {
        string res;
        if (k == 0 || nums.empty())
            return res;
        int len = nums.size();
        //because dp[i][j] depends on dp[i-1][j-1] and dp[i][j-1]
        vector<vector<string>> dp(2, vector<string>(len+1, ""));
        for (int i = 1; i <= k; i ++) {
            for (int j = 1; j <= len; j ++) {
                dp[i&1][j] = strMax(dp[(i-1)&1][j-1]+to_string(nums[j-1]), dp[i&1][j-1]);
            }
        }
        cout << "debug" << endl;
        return dp[k&1][len];
    }
    
    
    string helper_regardless_of_k(vector<int> & nums, int k) {
        string res;
        if (k == 0 || nums.empty())
            return res;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            while (!res.empty() && len-i+res.size() > k && nums[i] > (res.back()-'0'))
                res.pop_back();
            if (res.size() < k)
                res.push_back(nums[i]+'0');
        }
        return res;
    }
    
    string merge(string s1, string s2, int k) {
        int i = 0;
        int j = 0;
        int l = 0;
        int len1 = s1.length();
        int len2 = s2.length();
        string res;
        
        for (l = 0; l < k; l ++) {//find k digits to maximize the result
            string str1 = s1.substr(i);
            string str2 = s2.substr(j);
            if (str1.compare(str2) > 0) {
                res.push_back(s1[i]);
                i ++;
            }
            else {
                res.push_back(s2[j]);
                j ++;
            }
        }
        
        return res;
    }
    
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 + len2 < k)
            return res;//impossible to consutrct such a result
        string maxCandidate;
        cout << merge("67", "604",5) << endl;
        for (int l1 = max(0,k-len2); l1 <= len1 && l1 <= k; l1 ++) {
            //string s1 = helper_2D_DP(nums1, l1);
            //string s2 = helper_2D_DP(nums2, k-l1);
            
            //string s1 = helper_2D_DP_lessSpace(nums1, l1);
            //string s2 = helper_2D_DP_lessSpace(nums2, k-l1);
            
            string s1 = helper_regardless_of_k(nums1, l1);
            string s2 = helper_regardless_of_k(nums2, k-l1);
            string tmp = merge(s1, s2, k);
            maxCandidate = strMax(maxCandidate, tmp);
        }
        
        for (auto c : maxCandidate)
            res.push_back(c-'0');
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
