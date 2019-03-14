#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a ,b,c,sum=1;
    cin>>a>>b>>c;
    sum=a+b+c;
    while(sum!=0)
    {
        if(c-b==b-a)//ap
        {
            cout<<"AP "<<c+(c-b);
        }
        else
        {
            cout<<"GP "<<c*(c/b);
        }
        cout<<endl;
        cin>>a>>b>>c;
        sum=a+b+c;
    }
    return 0;
}