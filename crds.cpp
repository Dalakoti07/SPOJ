#include<bits/stdc++.h>
using namespace std;
int arr[1000001];

void go()
{
    arr[1]=2;
    long long temp;
    for(int i=2;i<=1000000;i++)
    {
        temp=(i-1)+2*i+arr[i-1];
        arr[i]=temp%(int(1e6)+7);
    }
}

int main()
{
    int t;
    cin>>t;
    go();
    while(t--)
    {
        int n;
        cin>>n;
        //do the precomputation and answer in O(1)
        cout<<arr[n]<<endl;
    }
}