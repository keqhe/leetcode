
class Solution {
public:
    //check the 1st round's explnation
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-gas-station.html
    //similar to "celebrity problem"
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int netGas = 0;
        for (int i = 0; i < gas.size(); i ++) {
            netGas += gas[i] - cost[i];
        }
        if (netGas < 0)
            return -1;
        int start = 0;
        int currGas = 0;
        for (int i = 0; i < gas.size(); i ++) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        return start;
    }
};
