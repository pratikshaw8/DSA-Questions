// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> Q)
{
    // add code here.
    vector<int> temp;
    
    while(!Q.empty())
    {
        temp.push_back(Q.front());
        Q.pop();
    }
    
    for(int i=temp.size()-1;i>=0;i--)
    {
        Q.push(temp[i]);
        
    }
    
    return Q;
}