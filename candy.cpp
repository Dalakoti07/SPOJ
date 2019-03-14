#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n!=-1)
    {
        int arr[n];
        int sum=0,temp,i=0;
        while(i<n)
        {
            cin>>arr[i++];
            sum+=arr[i-1];
        }
        int mean=sum/n,reserve=0;
        if(sum%n !=0 or mean*n>sum)
            cout<<"-1\n";
        else
        {
            int answer=0;
            for(int i=0;i<n;i++)
            if(mean>arr[i])
                answer+=mean-arr[i];
            cout<<answer<<endl;
        }
        cin>>n;
    }
}