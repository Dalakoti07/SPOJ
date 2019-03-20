#include<bits/stdc++.h>
# define LL long long
using namespace std;

struct node
{
    LL maxsum,sum,bps,bss;
};

void build(LL arr[],node* tree,LL start,LL end,LL index)
{
    if(start==end)
    {tree[index].maxsum=tree[index].sum=tree[index].bps=tree[index].bss=arr[start];return;}
    LL mid=(start+end)/2;
    build(arr,tree,start,mid,index*2);
    build(arr,tree,mid+1,end,index*2+1);
    node left=tree[index*2];
    node right=tree[index*2+1];
    tree[index].sum=left.sum+right.sum;
    tree[index].maxsum=max(left.maxsum,max(right.maxsum,max(left.sum+right.bps,max(left.bss+right.bps,right.sum+left.bss))));
    tree[index].bps=max(left.bps,left.sum+right.bps);
    tree[index].bss=max(right.bss,right.sum+left.bss);
}
node query(node* tree,LL start,LL end,LL index,LL a,LL b)
{
    //no overlap return -infinity
    if(start>b or a>end)
    {node temp;temp.maxsum=temp.sum=temp.bps=temp.bss=-1000000000;return temp;}
    // full overlap retunr the details of current node
    else if(start>=a and end<=b)
        return tree[index];
    //partial overlap
    else
    {
        LL mid=(start+end)/2;
        node left=query(tree,start,mid,index*2,a,b);
        node right=query(tree,mid+1,end,index*2+1,a,b);
        node temp;
        temp.sum=left.sum+right.sum;
        temp.maxsum=max(left.maxsum,max(right.maxsum,max(left.sum+right.bps,max(left.bss+right.bps,right.sum+left.bss))));
        temp.bps=max(left.bps,left.sum+right.bps);
        temp.bss=max(right.bss,right.sum+left.bss);
         return temp;
    }
}
int main() 
{
    // segment tree uses divide and conquer paradigm
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    LL arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* tree=new node[4*n];
    build(arr,tree,0,n-1,1);
    int q,a,b;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        node answer=query(tree,0,n-1,1,a-1,b-1);
        cout<<answer.maxsum<<endl;
    }
}