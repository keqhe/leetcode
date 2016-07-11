
class Solution {
public:
    //using k digits in nums to form a largest numbers
    string helper(vector<int>&nums, int k) {
        string res;
        if (k == 0)
            return "";
            
        stack<int> st;
        for (int i = 0; i < nums.size(); i ++) {
            while (!st.empty() && st.top() < nums[i] && (st.size() + (nums.size()-i-1)) >= k) {
                st.pop();
            }
            st.push(nums[i]);
        }
        
        while (!st.empty()) {
            res += st.top()+'0';
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string merge(string s1, string s2, int k) {
        int i = 0;
        int j = 0;
        string res;
        for (int l = 0; l < k; l ++) {
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
    bool compareStr(string s1, string s2) {
        while (s1.length() > 1 && s1.front() == '0')
            s1.erase(s1.begin());
        while (s2.length() > 1 && s2.front() == '0')
            s2.erase(s2.begin());
        if (s1.length() != s2.length())
            return s1.length() > s2.length();
        else {
            return s1 > s2;
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        if (nums1.empty() && nums2.empty())
            return res;
        if (nums1.empty()) {
            string x = helper(nums2, k);
            for (int i = 0; i < x.length(); i ++) {
                res.push_back(x[i]-'0');
            }
            return res;
        }
        if (nums2.empty()) {
            string x = helper(nums1, k);
            for (int i = 0; i < x.length(); i ++) {
                res.push_back(x[i]-'0');
            }
            return res;
        }
        string maxStr;
        for (int l = max(0, k-(int)nums2.size()); l <= k && l <= nums1.size(); l ++) {
            
            string s1 = helper(nums1, l);
            string s2 = helper(nums2, k-l);
            string s = merge(s1, s2, k);
            //cout <<l << " "<<  s1 << " " << s2 << " " << s << endl;
            if (compareStr(s, maxStr))
                maxStr = s;
        }
        
        for (int i = 0; i < maxStr.length(); i ++) {
            res.push_back(maxStr[i]-'0');
        }
        return res;
    }
};
