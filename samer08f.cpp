#include<bits/stdc++.h>
using namespace std;

int go(int n)
{
    return n*(n+1)*(2*n+1)/6;
}

int main()
{
    int x;
    cin>>x;
    while(x!=0)
    {
        cout<<go(x)<<endl;
        cin>>x;
    }
}