#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
        {
            if(a%2==0)
            cout<<2*b;
            else
            cout<<2*a-1;
        }
        else if(a-2==b)
        {
            if(a%2==0 and b%2==0)
            cout<<a+b;
            else if(a%2==1 and b%2==1)
            cout<<a+b-1;           
        }
        else
            cout<<"No Number";
        cout<<endl;
    }
}