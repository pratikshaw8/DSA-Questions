class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2-ax1) * (ay2-ay1);
        int a2 =(bx2-bx1) * (by2-by1);
        
        int left = max(bx1,ax1), right = min(ax2,bx2);
        int x = right-left;
        
        int top = min(ay2,by2), bottom = max(by1,ay1);
        int y = top-bottom;
        
        int intersection=0;
        if(x>0 and y>0)
        {
            intersection = x*y;
        }
        
        
        
        return a1+a2 - intersection;
        
    }
};