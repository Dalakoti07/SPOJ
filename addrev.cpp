#include<iostream>
using namespace std;

int reversenum(int x)
{
    int a=0;
    while(x!=0)
    {
        a=a*10+x%10;
        x/=10;
    }
    return a;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        int rx,ry;
        rx=reversenum(x);
        ry=reversenum(y);
        cout<<reversenum(rx+ry)<<endl;
    }
}