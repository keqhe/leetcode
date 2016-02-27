#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*note that this is actually greedy, but because this is one 
of the stock problems, just put it here */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] >= prices[i-1]) {
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
};

int main() {
	class Solution sn;
	return 0;
}
