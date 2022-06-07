class Solution {
public:
    int maxProfit(vector<int>& price) {
        int lsf=price[0];
        int op=0,mpist=0;
        int n=price.size();
        vector<int> left(n);
        vector<int> right(n);

        for(int i=1;i<n;i++)
        {
            if(lsf > price[i])
            lsf=price[i];

            mpist=price[i]-lsf;

            if( mpist > left[i-1])
            {
                left[i]=mpist;
            }
            else
            {
                left[i]=left[i-1];
            }



        }

        int mpibt=0;
        int hsf=price[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(hsf< price[i])
            hsf=price[i];

            mpibt=hsf-price[i];

            if(mpibt > right[i+1])
                right[i]=mpibt;
            else
                right[i]=right[i+1];

        }

        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,left[i]+right[i]);
        }
        return maxi;
    }
};