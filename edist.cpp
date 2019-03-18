#include<bits/stdc++.h>
using namespace std;

int go(string s1,string s2)
{
    // will go by dp
    int n=s1.length(),m=s2.length();
    int **dp= new int*[n+1];
    for(int i=0;i<n+1;i++)
        dp[i]=new int[m+1];

    for(int i=0;i<=m;i++)
        dp[0][i]=i;
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(s1[n-i]==s2[m-j])
        dp[i][j]=dp[i-1][j-1];
        else
        dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
    }
    return dp[n][m];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string one,two;
        cin>>one>>two;
        cout<<go(one,two)<<endl;
    }
}