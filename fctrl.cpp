#include<bits/stdc++.h>
using namespace std;

int go(int a)
{
    int count=0,temp=-1,power=1;
    while(temp!=0)
    {
        temp=a/pow(5,power);
        count+=temp;
        power++;
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        cout<<go(a)<<endl;
    }
}