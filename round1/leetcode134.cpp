
class Solution {
public:
    //key is that there is a guaranteed solution
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-gas-station.html
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 0)
            return -1;
        int netGas = 0;
        for (int i = 0; i < n; i ++) {
            netGas += gas[i] - cost[i];
        }
        if (netGas < 0)
            return -1;
        int start = 0;
        int curGasSum = 0;
        for (int i = 0; i < n; i ++) {
            curGasSum += gas[i] - cost[i];
            if (curGasSum < 0) {
                start = i + 1;
                curGasSum = 0;
            }
        }
        return start;
    }
};
