#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x;
        cin>>n>>m;
        multiset<int> good;
        multiset<int> bad;
        while(n--)
        {
            cin>>x;
            good.insert(x);
        }
        while(m--)
        {
            cin>>x;
            bad.insert(x);
        }
        // now the army is ready and what we would do is 
        while(good.size()>0 and bad.size()>0)
        {
            auto git=good.begin();
            auto bit=bad.begin();
            if(*git>=*bit)
            bad.erase(bit);
            else if(*bit>*git)
            good.erase(git);
        }
        /*
            We donot require stimulation this can be done in constant time as follows
            auto git=good.end();
            auto bit=bad.end();
            bit--;
            git--;
            int power_g=*git;
            int power_b=*bit;
            if(power_g>=power_b)
            cout<<"Godzilla\n";
            else
            cout<<"MechaGodzilla\n";
            think why? ,nice :)
        */
        if(good.size()==0)
        cout<<"MechaGodzilla\n";
        else
        cout<<"Godzilla\n";
    }
}