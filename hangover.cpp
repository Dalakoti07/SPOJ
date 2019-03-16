#include<bits/stdc++.h>
using namespace std;

int go(float length)
{
    float sum=0;
    int count=1;
    while(sum<=length)
    {
        sum+=1.0/(count+1);
        count++;
    }
    return count-1;
}

int main()
{
    float length;
    cin>>length;
    while(length!=0.00)
    {
        cout<<go(length)<<" card(s)"<<endl;
        cin>>length;
    }
    return 0;
}