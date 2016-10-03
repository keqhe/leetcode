class Solution {
public:
    //F(n) - F(n-1) = sum(A) - (n)*curr_last
    int maxRotateFunction(vector<int>& A) {
        if (A.empty())
            return 0;
        if (A.size() == 1)
            return 0;
        int sum = 0;
        for (auto x : A)
            sum += x;
        deque<int> de;
        for (auto x : A)
            de.push_back(x);
            
        int prev = 0;
        for (int i = 0; i < A.size(); i ++) {
            prev += i*A[i];
        }
        int max_val = prev;
        for (int j = 1; j < A.size(); j ++) {
            int curr = prev + sum - de.back()*A.size();
            de.push_front(de.back());
            de.pop_back();
            max_val = max(max_val, curr);
            prev = curr;
        }
        return max_val;
    }
};
