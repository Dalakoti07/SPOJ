#include<bits/stdc++.h>
using namespace std;


long long solve(int A[], int n)
{
	// Write your code here.
	if(n<=1)
		return 0;
	int i=0,left_arr[n/2],right_arr[n-n/2];
	for(;i<n/2;i++)
		left_arr[i]=A[i];
	for(int j=0;i<n;i++,j++)
		right_arr[j]=A[i];
	long long left=solve(left_arr,n/2);
	long long right=solve(right_arr,n-n/2);
	//merging
	long long f_count=0,count=0;
	i=0;
	int j=0,k=0;
	while((i<n/2) and (j<(n-n/2)))
	{
		if(left_arr[i]>right_arr[j])
			{count+=n/2-i;A[k++]=right_arr[j++];}
		else
			A[k++]=left_arr[i++];
	}
	if(i==n/2)
	{
		while(j!=(n-n/2))
		{
			A[k++]=right_arr[j++];
		}
	}
	else
	{
		while(i!=n/2)
		{
			A[k++]=left_arr[i++];
		}
	}
	f_count=count+left+right;
	return f_count;
}
int main()
{
    // the brute force take n^2 time, thus sorting used
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        cout<<solve(arr,n)<<endl;
    }
}