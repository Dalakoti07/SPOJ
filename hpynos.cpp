#include<bits/stdc++.h>
using namespace std;

int go(int n)
{
    vector<int> digits;
    while(n!=0)
    {
        digits.push_back(n%10);
        n/=10;
    }
    int nn=0;
    for(auto i=digits.begin();i!=digits.end();i++)
    {
        nn+=(*i)*(*i);
    }
    return nn;
}

int main()
{
    int n;
    cin>>n;
    map<int,bool> m;
    m[n]=true;
    int count=0;
    while(n!=1)
    {
        n=go(n);
        if(m.count(n)==1)
        break;
        m[n]=true;
        count++;
    }
    if(n!=1)
    cout<<"-1";
    else
    cout<<count;
}