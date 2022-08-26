class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l=0,h=height.size()-1;
        int res=0;
        
        
        while(l<h)
        {
            int mini=min(height[l],height[h]);
            int ans= mini * (h - l);
            
            res=max(res,ans);
            
            if(height[l] > height[h])
                h--;
            else
                l++;
        }
        return res;
    }
};