
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int y = min(D, H) - max(B, F);
        int x = min(C, G) - max(A, E);
        
        int cover = x*y;
        if ( min(C, G) <= max(A, E) || min(D, H) <= max(B, F)) //no overlap
            cover = 0;
        return (H-F)*(G-E) + (D-B)*(C-A) - cover;
    }
};
