#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
int n;
long long f[1 << 5][1005];
bool check(int x, int y){
	for (int i = 0; i < n; i++){
		bool bitx = (x >> i) & 1, bity = (y >> i) & 1; 
		if (bitx && bity){
			return false;
		} else if (!(bitx || bity)){
			if (((x >> (i+1)) & 1) || ((y >> (i+1)) & 1) || i == n - 1) return false;
			else i++;
		}
	}
	return true;
}
//void printbit(int x){
//	cout << '{';
//	for (int i = 0; i < n; i++)
//		cout << ((x >> i) & 1) << ' ';
//	cout << '}';
//}
int main(){
	freopen("board.in", "r", stdin);
	freopen("board.out", "w", stdout); 
	ios::sync_with_stdio(0);
    cin.tie(0);
	int m;
	cin >> n >> m;
	f[0][0] = 1;
	for (int i = 1; i <= m; i++)
		for (int s1 = 0; s1 < (1 << n); s1++)
			for (int s2 = 0; s2 < (1 << n); s2++)
				if (check(s1, s2)){
					f[s2][i] += f[s1][i-1];
					f[s2][i] %= mod;
				}
//	for (int i = 1; i <= m; i++){
//		cout << i << ":\n";
//		for (int s = 0; s < (1 << n); s++)
//			if (f[s][i]){
//				printbit(s);
//				cout << ':' << f[s][i] << '\n';
//			}
//		cout << '\n';
//	}
	cout << f[0][m] << '\n';
	return 0;
}



