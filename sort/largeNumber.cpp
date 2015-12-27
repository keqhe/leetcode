#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool mycmp(int n1, int n2) {
        string s1 = to_string(n1) + to_string(n2);
        string s2 = to_string(n2) + to_string(n1);

        return stol(s1) > stol(s2);
}

bool comparison(int i, int j)
{
    string string1 = to_string(i) + to_string(j);
    long int v1 = atol(string1.c_str());
    string string2 = to_string(j) + to_string(i);
    long int v2 = atol(string2.c_str());
    return (v1>v2);
};


class Solution {
public:
    //c++ sort, 
    //comp function:
    //The value returned indicates whether the element passed as first argument is 
    //considered to go before the second in the specific strict weak ordering it defines.

    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty())
            return res;
            
        sort(nums.begin(), nums.end(), mycmp);
        if (nums[0] == 0)
		return "0";
	for (int i = 0; i < nums.size(); i ++) {
		res += to_string(nums[i]);
	}
	return res;
    }
};

int main() {
	vector<int> nums {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	class Solution sn;
	cout << sn.largestNumber(nums) << endl;
	return 0;
}
