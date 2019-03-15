#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,x;
    // test cases are also big thus take long long
    cin>>t;
    while(t--)
    {
        long long int n,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum=(sum+x)%n;
        }
        if(sum==0)
        cout<<"YES";
        else
        cout<<"NO";
        cout<<endl;
    }
    return 0;
}