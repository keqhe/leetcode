
bool str2Cmp(int num1, int num2) {
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    
    string com1 = s1 + s2;
    string com2 = s2 + s1;
    while (com1.length() > 1 && com1.front() == '0')
        com1.erase(com1.begin());
    while (com2.length() > 2 && com2.front() == '0')
        com2.erase(com2.begin());
    if (com1.length() == com2.length())
        return com1 > com2;
    else
        return com1.length() > com2.length();
}
bool strCmp(int num1, int num2) {
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    return (s1+s2) > (s2+s1);//if this is true, s1 goes first
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end(), strCmp);
        for (auto x : nums) {
            res += to_string(x);
        }
        while (res.length() > 1 && res.front() == '0')//think about test case : [0,0]
            res.erase(res.begin());
        return res;
    }
};
