
class Solution {
public:
    //n = 0, empty tree, ; f(0) = 1; 
    //n = 1, root node; f(1) = 1;
    //n = 2, 1 as the root: f(0)*f(1); 2 as the root, f(1)*f(0); total f(2) = f(0)*f(1) + f(1)*f(0)
    //n = 3; f(0)*f(2) + f(1)*f(1) + f(2)*f(0) = 5
    //f(n) = f(0)*f(n-1) + f(1)*f(n-2) + f(2)*f(n-3) +.. + f(n-1)*f(0)
    int numTrees(int n) {
        vector<int> nums(n+1, 0);
        nums[0] = 1;
        //nums[1] = 1;
        
        for (int i = 1; i <= n; i ++) {//i from 1 to n
            for (int j = 0; j <= i - 1; j ++) {
                int k = i - j - 1;
                nums[i] += nums[j]*nums[k];
            }
        }
        return nums[n];
    }
};
