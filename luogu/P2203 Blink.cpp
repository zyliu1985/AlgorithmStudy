#include <iostream>
#include <algorithm>
using namespace std;

int vis[1 << 16], lst[1 << 16];
int n;
bool now[20];
int calc(){
	int cal = 0;
	for (int i = 1; i <= n; i++)
		cal = (cal << 1) + now[i];
	return cal;
}
void cocalc(int x){
	for (int i = n; i >= 1; i--)
		now[i] = x & 1, x >>= 1;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	long long b;
	cin >> n >> b;
	for (int i = 1; i <= n; i++){
		cin >> now[i];
	}
	int id = 0;
	while (id < b){
		int x = calc();
		if (vis[x]){
			cocalc(lst[vis[x] + (b - vis[x]) % (id - vis[x] + 1)]);
			for (int i = 1; i <= n; i++)
				cout << now[i] << '\n';
			return 0;
		}
		vis[x] = id;
		lst[id] = x;
		id++;
		int t = now[n];
		for (int i = n; i >= 2; i--)
			now[i] ^= now[i-1];
		now[1] ^= t;
	}
	for (int i = 1; i <= n; i++)
		cout << now[i] << '\n';
	return 0;
}



