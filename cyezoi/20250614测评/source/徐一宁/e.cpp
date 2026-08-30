#include<bits/stdc++.h>
using namespace std;

#define ee endl;

int k,n,m,A,B,bg[2100][10010]={};
long long mn=999999;

struct hx{
	int a,b,t,h;
};

hx s[10100];


void gogogo(int no,int ck,int ti){
	cout<<no<<" "<<ck<<" "<<ti<<endl;
	if(ti=mn&&no!=B)return;
	if(ti>mn)return;
	if(ck<=0)return;
	if(no==B){
		mn=ti;
		return;
	}
	int i=1;
	while(bg[no][i]!=0){
		if(no=s[bg[no][i]].a){
			gogogo(s[bg[no][i]].b,ck-s[bg[no][i]].h,ti+s[bg[no][i]].t);
		}
		else{
			gogogo(s[bg[no][i]].a,ck-s[bg[no][i]].h,ti+s[bg[no][i]].t);
		}
		i++;
	}
}

int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i].a>>s[i].b>>s[i].t>>s[i].h;
		for(int j=1;j<=10010;j++){
			if(bg[s[i].a][j]==0){
				bg[s[i].a][j]=i;
				break;
			}
		}
		for(int j=1;j<=10010;j++){
			if(bg[s[i].b][j]==0){
				bg[s[i].b][j]=i;
				break;
			}
		}
	}
	cin>>A>>B;
	gogogo(A,k,0);
	if(mn==999999){
		cout<<-1;
	}
	else{
		cout<<mn;
	}
	return 0;
}
