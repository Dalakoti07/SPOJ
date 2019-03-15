#include<bits/stdc++.h>
using namespace std;
/*
int go(int base,int power)
{
    base=base%10;
    int answer=base;
    Better use chinese remainder theorem or modular exponentiation where we can find (a^b)%p since here we want to find the last digit here p would be 10, so lets go 
    */
    /* this brute force method would give AC thus commented for(int i=2;i<=power;i++)
    return answer;
    answer=(answer*base)%10;
}
*/

int go(int b,int pow)
{
    // using modular exponentiation and by the help of recursion complexity reduced from O(power) to O(log power)
    long long answer=0;
    if(pow==0)
    return 1;
    else if(b==0)
    return 0;
    if(pow%2==0)
    {
        answer=go(b,pow/2);
        answer=(answer*answer)%10;
    }
    else
    {
        answer=go(b,pow-1);
        answer=(b*answer)%10;
    }
    return answer;
}

int main()
{
    //constraints are too tight that brute force wont work
    int test;
    cin>>test;
    while(test--)
    {
        int a,b;
        cin>>a>>b;
        cout<<go(a,b)<<endl;
    }
}