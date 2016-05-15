
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        unordered_map<int, int> m;//number, number of times it appears
        for (int i = 0; i < secret.length(); i ++) {
            if (secret[i] == guess[i])
                bull ++;
            else
                m[secret[i]] ++;
        }
        for (int i = 0; i < guess.length(); i ++) {
            if (secret[i] != guess[i]) {
                if (m.find(guess[i]) != m.end()) {
                    if (m[guess[i]] > 0) {
                        cow ++;
                        m[guess[i]] --;
                    }
                }
            }
        }
        return to_string(bull)+"A" + to_string(cow) + "B";
        
    }
};
