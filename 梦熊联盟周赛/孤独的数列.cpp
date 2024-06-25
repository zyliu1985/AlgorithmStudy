#include <iostream>
#include <cstring>
using namespace std;

int a[200005];
bool da[200005][25];
int num[25];
int n;
bool check(int mid){
	for (int i = 1; i <= n; i++){
		if (i <= mid){
			for (int j = 1; j <= 21; j++){
	
			}
		}
	}
	return true;
}
void set_da(int x){
	int cur = 0;
	while (a[x] > 0){
		cur++;
		da[x][cur] = a[x] % 2;
		a[x] /= 2;
	}
}
int main(){
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++){
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		memset(sda, 0, sizeof(sda));
		for (int i = 1; i <= n; i++)
			set_da(i);
		int l = 1, r = n;
		while (l < r){
			int mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}