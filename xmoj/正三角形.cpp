#include <iostream>
#include <algorithm>
using namespace std;

double l[3][4005];
int cur[3];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	f[0][1] = f[1][1] = f[2][1] = 1;
	cur[0] = cur[1] = cur[2] = 1;
	for (int i = 1; i <= n; i++){
		int p, a, b;
		cin >> p >> a >> b;
		l[p][++cur[p]] = a * 1.0 / (a + b)
	}
	sort(l[1]+1, l[1]+cur[1]+1);
	sort(l[2]+1, l[2]+cur[2]+1, cmp);
	long long ans = 0;
	for (int o = 1; o <= cur[0]; o++)
		for (){
		}
			
	return 0;
}

