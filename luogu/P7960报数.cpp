#include <iostream>
#include <cstring>
using namespace std;

bool can[10000005];
int f[10000005];
bool chai(int x){
	while (x > 0){
		int y = x % 10;
		if (y == 7) return true;
		x /= 10;
	}
	return false;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	memset(can, true, sizeof(can));
	for (int i = 1; i <= 10000000; i++)
		if (can[i])
			if (chai(i)){
				can[i] = false;
				for (int j = i * 2; j <= 10000000; j += i)
					can[j] = false;
			}
	for (int i = 1; i <= 10000000; i++)
		if (can[i]){
			int t = i;
			while (!can[++i] && i <= 10000000);
			i--;
			f[t] = i + 1;
		}
	int t;
	cin >> t;
	while (t--){
		int x;
		cin >> x;
		if (!can[x]) cout << -1 << endl;
		else cout << f[x] << endl;
	}
	return 0;
}