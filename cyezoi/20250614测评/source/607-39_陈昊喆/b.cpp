#include<bits/stdc++.h>
using namespace std;
int c,ans;
bool m[200010][3];
bool f[200010][3];
void bfs(int x,int y){
	if(y!=1 and y!=2) return;
	if(x==0 or x>c) return;
	if(f[x][y]) return;
	
	f[x][y]=true;
	if(m[x][y]) ans-=2;
	else return;
	
	bfs(x-1,y);
	bfs(x+1,y);
	if(x%2==1) bfs(x,y+1);
	if(x%2==1) bfs(x,y-1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>c;
	for(int i=1;i<=c;i++){
		int tmp;cin>>tmp;
		if(tmp==1) m[i][1]=true,ans+=3;
	}
	for(int i=1;i<=c;i++){
		int tmp;cin>>tmp;
		if(tmp==1) m[i][2]=true,ans+=3;
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=c;i++){
		if(!f[i][1] and m[i][1]) bfs(i,1),ans+=2;
		if(!f[i][2] and m[i][2]) bfs(i,2),ans+=2;
	}
	for(int i=1;i<=c;i++){
		if(i%2==1){
			if(m[i][1] and m[i][2] and m[i+1][1] and m[i+1][2] and m[i+2][1] and m[1+2][2])
				ans-=2;
		}
	}
	cout<<ans;
	return 0;
}
/*
5
1 0 1 0 1
0 0 0 0 0

7
0 0 1 1 0 1 0
0 0 1 0 1 0 0

5
1 1 1 0 0 
1 1 1 0 0

5
1 1 1 1 1
1 1 1 1 1
*/
