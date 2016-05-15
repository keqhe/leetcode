
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int part1 = (C-A)*(D-B);
        int part2 = (G-E)*(H-F);
        int part3 = 0;
        //if (C > E && H > B)
        if (min(C, G) > max(E, A) && min(D, H) > max(B, F))
            part3 = (min(C, G) - max(E, A))*(min(D, H) - max(B, F));
        return part1 + part2 - part3;
    }
};
