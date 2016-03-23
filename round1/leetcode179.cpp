
class Solution {
public:
    //c++ sort, 
    //comp function:
    //The value returned indicates whether the element passed as first argument is 
    //considered to go before the second in the specific strict weak ordering it defines.
    static bool mycmp(int n1, int n2) {//must be static
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        
        string c1 = s1 + s2;
        string c2 = s2 + s1;
        
        return c1 > c2;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty())
            return res;
            
        sort(nums.begin(), nums.end(), mycmp);
        if (nums[0] == 0)
            return "0";
        for (int i = 0; i < nums.size(); i ++) {
            res += to_string(nums[i]);
            //cout << res << endl;
        }
        return res;
    }
};
