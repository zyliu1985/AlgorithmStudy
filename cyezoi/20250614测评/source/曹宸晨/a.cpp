#include <bits/stdc++.h>
using namespace std;
int box[10];
signed main()
{
	int n;
	scanf("%d",&n);
	char c;
	while(n--)
	{
		scanf("\n");
		for(int i = 0; i < 5; i++)
		{
			scanf("%c",&c);
			if(c == 'Y') box[i]++;
		}
	}
	int MAX = 0;
	for(int i = 0; i < 5; i++)
		MAX = max(MAX,box[i]);
	bool flag = false;
	for(int i = 0; i < 5; i++)
	{
		if(box[i] != MAX) continue;
		if(flag) printf(",");
		printf("%d",i + 1);
		flag = true;
	}
}
