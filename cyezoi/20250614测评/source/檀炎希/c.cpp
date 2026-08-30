#include<bits/stdc++.h>
using namespace std;
long long  b[5005][5005],a[10000],sums[5005][5005];
int main()
{
	int n;cin>>n;long long minn=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];b[1][i]=0;
	} 	
    	for(int i=2;i<=n;i++)
	{
		
		b[2][i]=abs(a[i]-a[i-1]);
		 minn=min(minn,b[2][i]); 
	} 
	cout<<0<<" "<<minn<<" ";
    for(int i=3;i<=n;i++)
    {
    	long long minn=0x3f3f3f3f3f3f3f3f;
        for(int j=i;j<=n;j++)
        {
        	b[i][j]=b[i-2][j-1]+abs(a[j]-a[j-i+1]);
        	minn=min(minn,b[i][j]);
		}
		cout<<minn<<" ";
    }
	/*
	00000000000000000000000
	00000000000000000000000
	00001111100000111110000
	00001111100000111110000
	00001111100000111110000
	00000000000000000000000
	00000000011111000000000
	00000000011111000000000
	00000011111111111000000
	00000011111111111000000
	00000011111111111000000
	00000011100000111000000
    00000000000000000000000
    CREEPER 保佑 代码无BUG! 
    
    
    
    
    300分 
    */
}

