#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //ref: https://leetcode.com/discuss/58120/share-my-c-o-logn-solution-with-explanation
    //
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int left = 0;
        int right = citations.size() - 1;
        int index;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (citations[citations.size()-mid-1] > mid) //mid+1 papers have at least mid+1 citations
            {
                left = mid + 1;
                index = mid;
            }
            else
                right = mid - 1;
        }
        return left;
    }
};

int main() {
	class Solution sn;	
	return 0;
}
