
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //return naive(prices);
        return helper(prices);
    }
    
    int helper(vector<int> & p) {
        if (p.size() == 0 || p.size() == 1)
            return 0;
        int minimum = p[0];
        int profit = p[1] - p[0];
        
        for (int i = 1; i < p.size(); i ++) {
            if (p[i] - minimum > profit)
                profit = p[i] - minimum;
            if (p[i] < minimum)
                minimum = p[i];
        }
        
        if (profit < 0)
            return 0;
        else
            return profit;
    }
    
    //Time Limite Exceeded, O(n^2) time complexity and O(1) space
    int naive(vector<int> & prices) {
        int largest = 0;
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
            
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j ++) {
                if (prices[j] - prices[i] > largest)
                    largest = prices[j] - prices[i];
            }
        }
        
        return largest;
    }
};
