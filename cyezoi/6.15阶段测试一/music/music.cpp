#include <iostream>
#include <cstdio>
using namespace std;

int a[55];
bool flag[7];
int main(){
//	freopen("music.in","r",stdin);
//  	freopen("music.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
		flag[a[i] % 7] = true;
	}
	int ans = 0;
	for (int i = 0; i < 7; i++)
		ans += flag[i];
	cout << ans << endl;
	return 0;
}
