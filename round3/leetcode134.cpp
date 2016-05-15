
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (cost.empty())
            return -1;
        int start = 0;
        int accGas = 0;
        int accCost = 0;
        for (int i = 0; i < gas.size(); i ++) {
            accGas += gas[i];
            accCost += cost[i];
        }
        if (accGas < accCost)
            return -1;
        int currGas = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i ++) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                index = i + 1;
                currGas = 0;
            }
        }
        if (index == gas.size())
            return -1;
        else
            return index;
    }
};
