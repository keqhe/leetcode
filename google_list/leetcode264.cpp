
class Solution {
public:
    /*
    申请一个长度为n的数组uglyNumbers，用于从小到大顺序存储n个丑数，数组中的首项为1，即第一个丑数为1
设置三个变量idx2、idx3、idx5存储下标，初始值都为0
找出数组uglyNumbers[idx2]*2、uglyNumbers[idx3]*3、uglyNumbers[idx5]*5的最小值，最小值即为下一个丑数，同时更新最小值对应的下标，如果多个数字同时为最小值，则它们的下标都要更新
找到第n个丑数时，循环结束
    */
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        vector<int> uglynumbers(n, 0);
        uglynumbers[0] = 1;
        vector<int> primes = {2,3,5};
        vector<int> index(3, 0);
        for (int i = 1; i < n; i ++) {
            int curr_min = uglynumbers[index[0]]*primes[0];
            for (int j = 1; j < primes.size(); j ++) {
                curr_min = min(curr_min, uglynumbers[index[j]]*primes[j]);
            }
            uglynumbers[i] = curr_min;
            
            for (int j = 0; j < primes.size(); j ++) {
                if (curr_min == uglynumbers[index[j]]*primes[j])
                    index[j] ++;
            }
        }
        return uglynumbers[n-1];
    }
};
