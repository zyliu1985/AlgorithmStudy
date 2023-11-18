#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int t, f1[100005], f2[100005];
signed main(){
	f1[1] = 1;
	f2[1] = 8;
	for (int i = 2; i <= 100005; i++){
		f1[i] = f1[i-1]*9 + f2[i-1];
		f1[i] %= 998244353;
		f2[i] = f2[i-1]*9 + f1[i-1];
		f2[i] %= 998244353;
	}
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n, k;
		scanf("%d %d", &n, &k);
		if (n == 1){
			printf("%d\n", 9);
			continue;
		}
		printf("%d\n", f2[n]);
	}
	return 0;
}