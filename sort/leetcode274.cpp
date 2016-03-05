#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //ref: sort-based: https://leetcode.com/discuss/79740/according-to-the-definition-of-h-index-in-wiki-it-is-simple
    //[6,5,3,1,0]
    int hIndex_time(vector<int>& citations) {
        if (citations.empty())
            return 0;
        sort(citations.begin(), citations.end(), std::greater<int>());
        int n = citations.size();
        int i = 0;
        for (int i = 0; i < n; i ++) {
            if (citations[i] < i+1)//here, i is the (i+1) th paper, the (i+1)th paper's citation is small than (i+1)
                return i;
        }
        return n;
    }
    
    //O(n) time and O(n) space solution: ref; https://leetcode.com/discuss/73577/simple-java-o-n-time-o-n-space-solution
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        vector<int> temp(citations.size()+1, 0); //the number at position i means how many papers have a citation of i
        for (auto x : citations)
            temp[min(x, (int)citations.size())] ++;
        int sum = 0;
        for (int i = temp.size() -1 ; i >= 0; i --) {
            sum += temp[i];
            if (sum >= i)
                return i;
        }
    }
};

int main() {
	class Solution sn;
	return 0;
}
