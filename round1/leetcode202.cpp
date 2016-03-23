
class Solution {
public:
    vector<int> tested;
    bool isHappy(int n) {
        if (std::find(tested.begin(), tested.end(), n) != tested.end())
            return false;
        tested.push_back(n);
        if (n < 0)
            return false;
        else {
            string s = to_string(n);
            int square_sum = 0;
            for (int i = 0; i < s.length(); i ++) {
                int bit = atoi(s.substr(i,1).c_str());
                square_sum += bit*bit;
            }
            if (square_sum == 1)
                return true;
            else
                return isHappy(square_sum);
        }
    }
};
