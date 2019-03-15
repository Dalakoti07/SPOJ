#include<bits/stdc++.h>
using namespace std;

string go(string message,int col,int length)
{
    
    int row =length/col,x=0;
    // create the matrix row col
    char matrix[row][col];
    for(int i=0;i<row;i++)
    {
        if(i%2==0)
        for(int j=0;j<col;j++)
        {
            matrix[i][j]=message[x++];
        }
        else
        {
            for(int j=col-1;j>=0;j--)
            matrix[i][j]=message[x++];
        }
    }
    string answer="";
    for(int j=col-1;j>=0;j--)
        for(int i=row-1;i>=0;i--)
        answer+=matrix[i][j];
    reverse(answer.begin(),answer.end());
    return answer;
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        string message;
        cin>>message;
        int length=message.length();
        cout<<go(message,n,length)<<endl;
        cin>>n;
    }
}