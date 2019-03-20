#include<bits/stdc++.h>
using namespace std;
# define pi 3.14159

int main()
{
    int l;
    cin>>l;
    while(l!=0)
    {
        //use fixed otherwise it would give e^ something, the thinking was that build a hemispherical fence around the wall to get the max area between the wall and fence
        cout<<fixed<<setprecision(2)<<(l*l)/(2*pi)<<endl;
        cin>>l;
    }
}