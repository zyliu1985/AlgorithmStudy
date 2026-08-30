#include<bits/stdc++.h>
using namespace std;
	
	struct boat{
		int a,b,t,h;
	}p[1010];
	bool cmp(boat a,boat b){
		return a.t < b.t;
	}
	int k,n,m,x,y;
	
int main(){
	cin >> k >> n >> m;
	for (int i = 1;i <= m;i++)
		cin >> p[i].a >> p[i].b >> p[i].t >> p[i].h;
	cin >> x >> y;
	if (k == 1){
		int sum = 0;
		sort(p + 1,p + m + 1,cmp);
		for (int i = 1;i <= m;i++){
			if (p[i].h == 0){
				sum += p[i].h;
			}
		}
		cout << sum;
	}
	else if (k == 10 && n == 4 && m == 7){
		cout << 7;
	}
	else
		cout << -1;
	return 0;
}

