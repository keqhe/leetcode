
class Solution {
public:
    //a = min(G,C), x-axis right most
    //b = max(E,A), x-axis left most
    //c = min(H,D), y-axis, top most
    //d = max(F,B), y-axist, bottom most
    /*if (a <= b || c <= d)
        return 0;
    else
        return (a-b)*(c-d)
    */
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a, b, c, d;
        int m, n, p, q;
        int covered;
        int total;
        //A, B, C, D, E, F, G, H
        //0  0  0  0 -1 -1  1  1
        //
        a = min(G,C);//0
        b = max(E,A);//0
        c = min(H,D);
        d = max(F,B);
        
        if (a <= b || c <= d)
            covered =  0;
        else
            covered = (a-b)*(c-d);
        
        m = (C-A);
        n = (D-B);
        p = (G-E);
        q = (H-F);
        total = (m*n) + (p*q);
        return total - covered;
        
    }
};
