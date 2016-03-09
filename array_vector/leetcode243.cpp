#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int minDist = words.size() + 1;
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                if (index2 != -1) {
                    int tmp = i - index2;
                    minDist = min(minDist, tmp);
                    index1 = i;
                }
                else
                    index1 = i;
            }
            if (words[i] == word2) {
                if (index1 != -1) {
                    int tmp = i - index1;
                    minDist = min(minDist, tmp);
                    index2 = i;
                }
                else
                    index2 = i;
            }
        }
        return minDist;
    }
};

int main() {
	class Solution sn;
	return 0;
}
