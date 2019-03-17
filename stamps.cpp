#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i=1;
    cin>>t;
    while(t--)
    {
        int req,n;
        cin>>req>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        int x=n-1,sum=0;
        for(;x>=0 and sum<req;x--)
            sum+=arr[x];
        cout<<"Scenario #"<<i<<":"<<endl;
        if(sum>=req)
            cout<<n-x-1<<endl;
        else
            cout<<"impossible"<<endl;
        cout<<endl;
        i++;
    }
}