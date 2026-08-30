#include<bits/stdc++.h>
int n,a[5],id,cnt;
bool b[5];
std::string s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		std::cin>>s;
		a[0]+=(s[0]=='Y');
		a[1]+=(s[1]=='Y');
		a[2]+=(s[2]=='Y');
		a[3]+=(s[3]=='Y');
		a[4]+=(s[4]=='Y');		
	}
	b[0]=1,id=0;
	for(int i=1;i<5;i++){
		if(a[i]==a[id]){
			b[i]=1,cnt++;
		}
		else if(a[i]>a[id]){
			memset(b,0,sizeof b);
			id=i,cnt=0,b[i]=1;
		}
	}
	for(int i=0;i<5;i++){
		if(b[i]){
			printf("%d",i+1);
			if(cnt)printf(",");
			cnt--;
		}
	}
	return 0;
}
