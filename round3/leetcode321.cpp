
class Solution {
public:
    //compare two strings, s1 and s2, return the numerically larger one
    string maxStr(string s1, string s2) {
        while (!s1.empty() && s1.front() == '0')
            s1.erase(s1.begin());
        while (!s2.empty() && s2.front() == '0')
            s2.erase(s2.begin());
            
        if (s1.length() < s2.length())
            return s2;
        else if (s1.length() > s2.length())
            return s1;
        else if (s1.length() == s2.length()) {
            if (s1 > s2)
                return s1;
            else
                return s2;
        }
    }
    //given an array and number k, pick k digits that maximize the resulted number
    //the following helper uses stack technique
    string helper1(vector<int> & nums, int k) {
        string res;
        if (k == 0 || nums.empty())
            return res;
        for (int i = 0; i < nums.size(); i ++) {
            if (res.empty())
                res.push_back(nums[i]+'0');
            else {
                while (!res.empty() && nums[i] > (res.back()-'0') && 
                        ((nums.size()-i) + res.length()-1) >= k) {//think about 1,2,3,[4],5
                    res.pop_back();
                }
                res.push_back(nums[i]+'0');
            }
        }
        return res;
    } 
    
    //now the following method TLE, Apr 7, 2016
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
                dp[i][j] = maxStr(dp[i-1][j-1]+to_string(nums[j-1]), dp[i][j-1]);
            }
        }
        
        return dp[k][len];
    }
    /*the following merge is WRONG, think why, think about case [6,7] and [6,0,4]
    string merge(string s1, string s2, int k) {
        string res;
        if (k == 0)
            return res;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (cnt < k && i < s1.length() && j < s2.length()) {
            if (s1[i] > s2[j]) {
                res.push_back(s1[i]);
                i ++;
                cnt ++;
            }
            else {
                res.push_back(s2[j]);
                j ++;
                cnt ++;
            }
        }
        
        while (cnt < k && i < s1.length()) {
            res.push_back(s1[i]);
            i ++;
            cnt ++;
        }
        while (cnt < k && j < s2.length()) {
            res.push_back(s2[j]);
            j ++;
            cnt ++;
        }
        return res;
    }*/
    string merge(string s1, string s2, int k) {
        int i = 0;
        int j = 0;
        string res;
        for (int l = 0; l < k; l ++) {
            string str1 = s1.substr(i);
            string str2 = s2.substr(j);
            if (str1.compare(str2) > 0) {//the usage of compare here is cool
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
        if (nums1.empty() && nums2.empty() || k == 0 || nums1.size()+nums2.size() < k)
            return res;
        if (nums1.empty()) {
            string tmp = helper1(nums2, k);
            for (auto c : tmp)
                res.push_back(c-'0');
                return res;
        }
        if (nums2.empty()) {
            string tmp = helper1(nums1, k);
            for (auto c : tmp)
                res.push_back(c-'0');
                return res;
        }
        
        string candidate;
        for (int l = max(0, (int)(k-nums2.size())); l <= k && l <= nums1.size(); l ++) {
            
            string s1 = helper1(nums1, l);
            string s2 = helper1(nums2, k-l);
            
            /*string s1 = helper_2D_DP(nums1, l);
            string s2 = helper_2D_DP(nums2, k-l);
            */
            string s = merge(s1, s2, k);
            candidate = maxStr(candidate, s);
        }
        
        for (auto c : candidate) {
            res.push_back(c-'0');
        }
        return res;
    }
    //method 2, 3D DP, this version is TLE too, but a good exercise
    /*let dp[k][i][j] denote the max number of length k ending at most at nums1[i-1] and nums2[j-1]
    dp[0][*][*] = ""
    dp[k][i][j] = max(dp[k-1][i-1][j]+nums1[i-1], dp[k-1][i][j-1]+nums2[j-1], dp[k][i-1][j], dp[k][i][j-1], dp[k][i-1][j-1])
    */
    vector<int> maxNumber_3D_DP(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        if (nums1.empty() && nums2.empty() || k == 0 || nums1.size()+nums2.size() < k)
            return res;
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<vector<string>>> dp(k+1, vector<vector<string>>(m+1, vector<string>(n+1, "")));
        
        //takes 0 digits from nums1
        for (int l = 1; l <= k; l ++) {
            for (int j = 1; j <= n; j ++) {
                if (l > j)
                    dp[l][0][j] = "";
                else 
                    dp[l][0][j] = maxStr(dp[l-1][0][j-1]+to_string(nums2[j-1]), l <= j-1 ? dp[l][0][j-1] : "");
            }
        }
        //takes 0 digit from nums2
        for (int l = 1; l <= k; l ++) {
            for (int i = 1; i <= m; i ++) {
                if (l > i)
                    dp[l][i][0] = "";
                else
                    dp[l][i][0] = maxStr(dp[l-1][i-1][0]+to_string(nums1[i-1]), l <= i-1 ? dp[l][i-1][0] : "");
            }
        }
        for (int l = 1; l <= k; l ++) {
            for (int i = 1; i <= m; i ++) {
                for (int j = 1; j <= n; j ++) {
                    if (l > i+j)
                        continue;
                    
                    string s1 = dp[l-1][i-1][j]+to_string(nums1[i-1]);
                    string s2 = dp[l-1][i][j-1]+to_string(nums2[j-1]);
                    string s3 = (l <= i+j-2) ? dp[l][i-1][j-1] : "";
                    dp[l][i][j] = maxStr(s1, maxStr(s2, s3));
                }
            }
        }
        string candidate = dp[k][m][n];
        for (auto c : candidate) {
            res.push_back(c-'0');
        }
        return res;
    }
};
