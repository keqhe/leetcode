
class Solution {
public:
    //0  win
    //1 win
    //2 win
    //3 win
    //4 no
    //5 win
    //t(n-1) == 1, t(n-2) == 1, t(n-3) == 1, winner for n-1, n -2, n -3
    //if t(n) = !t(n-1) || !t(n-2) || !t(n-3)
    //DP Time Limit Error
    
    
    //correct thought
    /*
    for n = 1,2,3, you can win because you can take them all for the first shot
    for n = 4, you lose
    for n = 4 * 1 + (1, 2, 3), you can reduce the case to 2), you will win
    for n = 4 * 2, you lose
    for n = 4* 2 + (1, 2, 3)..
    */
    bool canWinNim(int n) {
        if (n<=0)
            return 0;
        return n%4;
    }
    bool canWinNim2(int n) {
        vector<bool> nums (4, 0);
        if (n <= 0)
            return 0;
        nums[0] = nums[1] = nums[2] = 1;
        for (int i = 4; i <= n; i ++) {
            nums[i%3] = !nums[(i-1)%3] || !nums[(i-2)%3] || !nums[(i-3)%3];
        }
        return nums[n-1];
    }
};
