#include<bits/stdc++.h>
using namespace std;
void buildtree(long long arr[],long long tree[],int s,int e,int index)
{
    if(s==e)
    { tree[index]=arr[s];return;}
    int mid=(s+e)/2;
    buildtree(arr,tree,s,mid,index*2);
    buildtree(arr,tree,mid+1,e,index*2+1);
    tree[index]=tree[index*2]+tree[index*2+1];
}

void update(long long lazy[],long long tree[],int s,int e,int index,int a,int b,int val)
{
    if(b<a)
    return;
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(a!=b)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(s>b or a>e)
    return ;
    if(a>=s and b<=e)
    {
        tree[index]+=val;
        if(a!=b)
        {
            lazy[2*index]+=val;
            lazy[2*index+1]+=val;
        }
        return;// this is lazzzy
    }
    int mid=(a+b)/2;
    update(lazy,tree,s,mid,index*2,a,b,val);
    update(lazy,tree,mid+1,e,index*2+1,a,b,val);
    tree[index]=tree[index*2]+tree[index*2+1];
}

int query(long long arr[],long long tree[],long long lazy[],int s,int e,int index,int a,int b)
{
    if(b<s or a>e)
    return 0;
    if(a>=s and b<=e)
    {
        if(lazy[index]==0)
        return tree[index];
        else
        {
            tree[index]+=lazy[index];
            if(s!=e)
            {
                lazy[2*index]+=lazy[index];
                lazy[2*index+1]+=lazy[index];
            }
            lazy[index]=0;
        }
    }
    else
    {
        int mid=(s+e)/2;
        long long left=query(arr,tree,lazy,s,mid,index*2,a,b);
        long long right=query(arr,tree,lazy,mid+1,e,index*2+1,a,b);
        return left+right;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        long long arr[n];
        for(int i=0;i<n;i++)
        arr[i]=0;
        long long tree[4*n];
        long long lazy[4*n];
        for(int i=0;i<4*n;i++)
        lazy[i]=0;
        int s,t,u,v;
        buildtree(arr,tree,0,n-1,1);
        while(c--)
        {
            cin>>s;
            if(s==1)
            {
                cin>>u>>v;
                cout<<query(arr,tree,lazy,0,n-1,1,u-1,v-1)<<endl;
            }
            else
            {
                cin>>t>>u>>v;
                update(lazy,tree,0,n-1,1,t-1,u-1,v);
            }
            
        }
    }
}