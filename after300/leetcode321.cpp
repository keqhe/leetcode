
class Solution {
public:
    //k must be <= nums.size()
    string maxNumber1D(vector<int>&nums, int k) {
        if (k == 0)
            return "";
        stack<int> st;
        for (int i = 0; i < nums.size(); i ++) {
            while (!st.empty() && nums[i] > st.top() && (st.size()-1+nums.size()-i) >= k) {
                st.pop();
            }
            st.push(nums[i]);
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top()+'0');
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> str2vec(string s) {
        vector<int> res;
        for (auto c : s)
            res.push_back(c-'0');
        return res;
    }
    //s1 and s2 should have the same length
    bool strCmp(string s1, string s2) {
        /*
        while (s1.length() > 1 && s1.front() == '0')
            s1.erase(s1.begin());
        while (s2.length() > 1 && s2.front() == '0')
            s2.erase(s2.begin());
        */
        return s1 < s2;
    }
    string mergeStr(string s1, string s2, int k) {
        string res;
        int i = 0;
        int j = 0;
        for (int l = 0; l < k; l ++) {
            string str1 = s1.substr(i);
            string str2 = s2.substr(j);
            //if (str1.compare(str2) > 0) {
            if (str1 > str2) {// it seems that str1.compare(str2) > 0 has the same effect as str1 > str2
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
        if (nums1.empty() && nums2.empty())
            return {};
        if (nums1.empty()) {
            string s = maxNumber1D(nums2, k);
            return str2vec(s);
        }
        if (nums2.empty()) {
            string s = maxNumber1D(nums1, k);
            return str2vec(s);
        }
        int m = nums1.size();
        int n = nums2.size();
        string maxStr;
        for (int i = 0; i <= min(m, k); i ++) {
            int j = k-i;
            if (j >= 0 && j <= n) {
                string s1 = maxNumber1D(nums1, i);
                string s2 = maxNumber1D(nums2, j);
                string s = mergeStr(s1, s2, k);
                if (s > maxStr) {
                    maxStr = s;
                }
            }
        }    
        vector<int> res;
        for (auto  c : maxStr)   
            res.push_back(c-'0');
        return res;
    }
};
