#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int c[405];
long long s[405][405];
long long dis[405][405], dis2[405][405];
int cdis[405][405], cdis2[405][405];
long long f[405][405], f2[405][405];
int cf[405][405];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m, ss;
	cin >> n >> m >> ss;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			int p;
			cin >> p;
			if (c[i]) p = 0;
			s[i][j] = s[i-1][j] + p;
		}
	memset(dis, 0x3f, sizeof(dis));
	memset(dis2, 0x3f, sizeof(dis2));
	for (int i = 1; i <= n; i++){
		int nowcolor = -1;
		for (int j = i; j <= n; j++){
			if (c[j] != 0){
				if (nowcolor == -1) nowcolor = c[j];
				else break;
			}
			if (nowcolor == -1){
				for (int k = 1; k <= m; k++){
					if (s[j][k] - s[i-1][k] < dis[i][j]){
						dis2[i][j] = dis[i][j];
						cdis2[i][j] = cdis[i][j];
						dis[i][j] = s[j][k] - s[i-1][k];
						cdis[i][j] = k;
					} else if (s[j][k] - s[i-1][k] < dis2[i][j]){
						dis2[i][j] = s[j][k] - s[i-1][k];
						cdis2[i][j] = k;
					}
				}
			} else {
				dis[i][j] = s[j][nowcolor] - s[i-1][nowcolor];
				cdis[i][j] = nowcolor;
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	memset(f2, 0x3f, sizeof(f2));
	f[0][0] = 0;
	cf[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= ss; j++)
			for (int k = i; k >= 1; k--){
				long long val;
				if (cf[k-1][j-1] == cdis[k][i]){
					val = f[k-1][j-1] + dis2[k][i];
					if (val < f[i][j]){
						f2[i][j] = f[i][j];
						f[i][j] = val;
						cf[i][j] = cdis2[k][i];
					} else if (val < f2[i][j])
						f2[i][j] = val;
					
					val = f2[k-1][j-1] + dis[k][i];
					if (val < f[i][j]){
						f2[i][j] = f[i][j];
						f[i][j] = val;
						cf[i][j] = cdis[k][i];
					} else if (val < f2[i][j])
						f2[i][j] = val;
				} else {
					val = f[k-1][j-1] + dis[k][i];
					if (val < f[i][j]){
						f2[i][j] = f[i][j];
						f[i][j] = val;
						cf[i][j] = cdis[k][i];
					} else if (val < f2[i][j])
						f2[i][j] = val;
				}
			}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= ss; j++)
//			cout << f[i][j] << ' ';
//		cout << '\n';
//	}
	if (f[n][ss] == 4557430888798830399) cout << -1 << '\n';
	else cout << f[n][ss] << '\n';
	return 0;
}
