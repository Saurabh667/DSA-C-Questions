class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int r1s1=ax2-ax1;
        int r1s2=ay2-ay1;
        int r2s1=bx2-bx1;
        int r2s2=by2-by1;
        
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1);
        int overlapHeight = min(ay2, by2) - max(ay1, by1);

        int overlap = 0;

        if (overlapWidth > 0 && overlapHeight > 0) {
            overlap = overlapWidth * overlapHeight;
        }

        int area =(r1s1*r1s2)+(r2s1*r2s2)-overlap;
        return area;
    }
};