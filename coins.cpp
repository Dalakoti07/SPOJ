#include<bits/stdc++.h>
using namespace std;
vector<long long> arr(1e8);

long long go(long long n)
{
    if(arr.size()>=n)
    return arr[n];
    else
    {
        return max(n,go(n/2)+go(n/3)+go(n/4));
    }
}

int main()
{
    // this question uses different types of input method
    // also this question requires u to use the dp array and recursion as dp array cannot by of size 1e9 ,so an amazing question
    long long n;
    // make the dp array here itself and answer the query in constant time 
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    arr[4]=4;
    for(long long i=5;i<1e8;i++)
        arr[i]=max(i,arr[i/2]+arr[i/3]+arr[i/4]);
    
    while(cin>>n)
    {
        if(n>=1e8)
        {
            cout<<go(n)<<endl;
        }
        else
        cout<<arr[n]<<endl;
    }
    return 0;
}