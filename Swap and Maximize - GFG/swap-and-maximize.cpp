// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int sum=0;
    int temp[n];
    
    sort(arr,arr+n);
    int i=0,j=n-1,c=0;
    int flag=0;
    while(c<n)
    {
        
        if(flag==0)
        {
            temp[c]=arr[i];
            i++;
            flag=1;
        }
        else
        {
            temp[c]=arr[j];
            j--;
            flag=0;
        }
        c++;
    }
    
    for(int i=1;i<n;i++)
    {
        long long int r=abs(temp[i]-temp[i-1]);
        sum+=r;
    }
    sum+=abs(temp[0]-temp[n-1]);
    return sum;
}