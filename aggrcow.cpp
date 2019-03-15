#include<bits/stdc++.h>
using namespace std;
// since the integers are too high so, doing mid =(start+end)/2 would give overflow , so do mid=strat+ (mid-start)/2
// always take care about the integer overflow, 
bool is_possible(int arr[],int N,int C,int dis)
{
  int count =1,last_index=0,curr;
  for(int i=0;i<N;i++)
  {
    if(arr[i]-arr[last_index]>=dis)
      {count++;last_index=i;}
    
  }
  return count>=C;
}

int go(int arr[],int N,int C)
{
 	int start=0,mid,end=arr[N-1]-arr[0],answer;
  while(start<=end)
  {
    mid=(start+end)/2;
    if(is_possible(arr,N,C,mid))
      {start=mid+1;answer=mid;}
    else
      end=mid-1;
  }
  return answer;
}

int main() 
{
  /*By brute force, its complexity would be O nd, where n and d are stalls and 
  range of the distance possible, with binary search it is n (log d)
  */
  int test;
  cin>>test;
  while(test--)
  {
    int N,C;
    cin>>N>>C;
    int arr[N];
    for(int i=0;i<N;i++)
      cin>>arr[i];
    sort(arr,arr+N);
    int answer=go(arr,N,C);
    cout<<answer<<endl;
  }
}