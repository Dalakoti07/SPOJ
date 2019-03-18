#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y,s;
        cin>>x>>y>>s;
        // handle the case if x==y means we have 5 terms, since i got ac without that thus test cases are weak
        long long n=(2*s)/(x+y);
        long d;
        cout<<n<<endl;
        d=(y-x)/(n-5);
        long a=x-2*d;
        for(int i=1;i<=n;i++)
        cout<<a+(i-1)*d<<" ";
        cout<<endl;
    }
}