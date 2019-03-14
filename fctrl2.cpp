#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
    int arr[500]={1};
    //calculate factorial
    int test;
    cin>>test;
    int i=1;
    while(i<=test)
    {
        arr[0]=1;
        //cout<<"enter the number";
        int n;
        cin>>n;
        int m=0,carry=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                arr[j]=(arr[j]*i)+carry;
                carry=arr[j]/10;
                arr[j]%=10;
            }
            while(carry)
            {
                m++;
                arr[m]=carry%10;
                carry/=10;
            }

        }
        for(int i=m;i>=0;i--)
            cout<<arr[i];
        cout<<endl;
        i++;
    }

}


