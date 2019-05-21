#include<bits/stdc++.h>
using namespace std;
#define MAXN 20
long long solveMem(int like[][MAXN],int N,int student,int mask,long long *dp)
{
    long long count=0;
    //cout<<"We are at n = "<<N<<"student = "<<student<<" mask = "<<mask;
    if(student==N)
    {
        if(mask==(1<<N)-1)
            {//cout<<"Returning 1\n";
             return 1;}
        else
            {//cout<<"returning 0\n";
             return 0;}
    }
    if(dp[mask]!=INT_MIN)
        return dp[mask];
    // calculations
    for(int i=0;i<N;i++)
    {
        //can this student be given this candy
        if(!(mask&(1<<i)) and like[student][N-i-1])
        {
            count+=solveMem(like,N,student+1,mask|(1<<i),dp);
        }
    }
    dp[mask]=count;
    //cout<<"returning at last "<<dp[mask]<<endl;
    return count;
}

long long solve(int like[][MAXN],int N)
{
    // we would try with memoization and first dp solution for this problem
    long long *dp=new long long[1<<N];
    for(int i=0;i<1<<N;i++)
        dp[i]=INT_MIN;
    solveMem(like,N,0,0,dp);
    //for(int i=0;i<1<<N;i++)
      //  cout<<dp[i]<<" ";
    long long answer=dp[0];
    delete[] dp;
    return answer;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int like[n][MAXN];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>like[i][j];
        cout<<solve(like,n)<<endl;
    }
}