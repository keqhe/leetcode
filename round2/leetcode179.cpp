
bool strCmp(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    
    string c1 = s1+s2;
    string c2 = s2+s1;
    return c1 > c2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end(), strCmp);
        if (nums[0] == 0)
            return "0";
        for (auto x : nums)
            res += to_string(x);
        return res;
    }
};
