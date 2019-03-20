#include<bits/stdc++.h>
using namespace std;

int go(int **arr,int n,int m)
{
    // make the dp array local
    int dp[n][m]={0};
    //copy the last row of arr to the dp itself
    for(int i=0;i<m;i++)
    dp[n-1][i]=arr[n-1][i];
    // make the dp array for other elements
    for(int i=n-2;i>=0;i--)
    {
        dp[i][0]=arr[i][0]+max(dp[i+1][0],dp[i+1][1]);//handle the first and last column]
        dp[i][m-1]=arr[i][m-1]+max(dp[i+1][m-2],dp[i+1][m-1]);
        for(int j=1;j<m-1;j++)
        {
            dp[i][j]=arr[i][j]+max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
        }
    }
    //find the max in the first row
    int maxso=INT_MIN;
    for(int i=0;i<m;i++)
    if(dp[0][i]>maxso)
    maxso=dp[0][i];
    return maxso;
}

int main()
{
    int t;
    cin>>t;
    //simple dp problem, though it cannot be solved by the greedy who know one path that seems right at first seems bad at last
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int** arr=new int*[n];
        for(int i=0;i<n;i++)
        arr[i]=new int[m];

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
        cout<<go(arr,n,m)<<endl;
        //delete the arry
        for(int i=0;i<n;i++)
        delete []arr[i];
    }
}