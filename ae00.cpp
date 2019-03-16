#include<bits/stdc++.h>
using namespace std;

int go(int n)
{
    int count=n;
    for(int i=2;i<=sqrt(n);i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(j*(i)>n)
            break;
            else
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<go(n);
}