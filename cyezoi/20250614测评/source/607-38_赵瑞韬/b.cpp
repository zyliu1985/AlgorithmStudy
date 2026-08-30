#include<bits/stdc++.h>
int c,cnt,a[200002],b[200002];
int main(){
	scanf("%d",&c);
	for(int i=1;i<=c;i++)scanf("%d",a+i);
	for(int i=1;i<=c;i++)scanf("%d",b+i);
	for(int i=0;i<=c;i++){
		if((!a[i])&&a[i+1]||a[i]&&(!a[i+1]))cnt++;
		if((!b[i])&&b[i+1]||b[i]&&(!b[i+1]))cnt++;
	}
	for(int i=1;i<=c;i++,i++){
		if((!a[i])&&b[i]||a[i]&&(!b[i]))cnt++;
	}
	for(int i=2;i<=c;i++,i++){
		if(a[i])cnt++;
		if(b[i])cnt++;
	}
	printf("%d",cnt);
	return 0;
}

