class Solution {
public:
    
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
       int x = max(x1,min(xc,x2));
       int y = max(y1,min(yc,y2));

        long long dx = x-xc;
        long long dy = y-yc;

        return dx*dx + dy*dy <= 1LL*r*r;
    }
};