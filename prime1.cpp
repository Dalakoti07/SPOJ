#include<bits/stdc++.h>
using namespace std;
//int space=1e9+1;
//bool* seive=new bool[space];

/*void precompute()
{
    for(int i=0;i<(1e9)+1;i++)
    {
        seive[i]=true;
    }// make all primes
    int upb=sqrt(1e9+1);
    for(int i=2;i<=upb;i++)
    {
        //mark all its multiples as not prime
        for(int j=2*i;j<=sqrt(i);j+=i)
        seive[j]=false;
    }
}
*/
bool check(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    if(a%i==0)
    return false;
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,start;
        cin>>n>>m;
        start=n;
        if(n==1)
        start=2;
        for(int i=start;i<=m;i++)
        {
            if(check(i))
            cout<<i<<endl;
        }
        cout<<endl;
    }    
    
}