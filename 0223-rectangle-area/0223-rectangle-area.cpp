class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2-ax1) * (ay2-ay1);
        int a2 =(bx2-bx1) * (by2-by1);
        
        int il ,ib;
        
        if((ax1 <= bx1 and ax2<=bx1) or (ax1>= bx2 and ax2>=bx2)
           or (ay1<=by1 and ay2<=by1) or (ay1>= by2 and ay2>=by2))
            return a1+a2;
        
        il = min(ax2,bx2) - max(ax1, bx1);
        ib = min(ay2,by2) - max(ay1,by1);
        
        return a1+a2 - il*ib;
        
    }
};