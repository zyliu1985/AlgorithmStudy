#include <iostream>
#include <cstdio>
using namespace std;

int a[100005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int maxi, maxn = 0, mini, minn = 1e9;
	for (int i = 1; i <= n; i++){
		if (a[i] >= maxn){
			maxn = a[i];
			maxi = i;
		} 
		if (a[i] <= minn){
			minn = a[i];
			mini = i;
		}
	}
	double sum = 0;
	for (int i = 1; i <= n; i++)
		if (i != maxi && i != mini) sum += a[i];
	printf("%.2f", sum/(n-2));
	return 0;
}