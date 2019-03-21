#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i=1;
	cin>>t;
	while(i<=t)
	{
		int n;
		cin>>n;
		long long arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		//dp array
		if(n>=2)
			arr[1]=max(arr[0],arr[1]);
		for(int i=2;i<n;i++)
			arr[i]=max(arr[i-1],arr[i]+arr[i-2]);
		cout<<"Case "<<i++<<": "<<arr[n-1]<<endl;
	}
}