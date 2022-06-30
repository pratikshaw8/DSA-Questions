// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
static bool mycmp(val a, val b)
{
    if(a.second==b.second)
    return a.first< b.first;
    return a.second< b.second;
}


int greedy(struct val p[],int n)
{
    sort(p,p+n,mycmp);
    
    int i=0,j=1,count=1;
    while(j<n)
    {
        if(p[i].second < p[j].first)
        {
            count++;
            i=j;
        }
        j++;
    }
    return count;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    //Your code here
   return greedy(p,n);
    
}