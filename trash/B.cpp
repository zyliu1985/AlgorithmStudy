#include <iostream>
#include <algorithm>
#include <random>
#include <cstring>
using namespace std;

int n, m, k;
int a[200005], t[200005], num[200005], cur;
int len[200005], lcur;
bool cmp(int x, int y){
	return x > y;
}
bool check(int x){
	for (int i = cur; i >= 1; i--){
		lcur = 0;
		int cnt = 0;
		bool conti = false;
		for (int j = 1; j <= n; j++){
			if (a[j] > num[i] || a[j] < num[i] - x){
//				cout << "0 ";
				conti = false;
			} else if (conti){
				cnt++;
//				cout << "1 ";
				len[lcur]++;
			} else {
//				cout << "1 ";
				cnt++;
				conti = true;
				len[++lcur] = 1;
			}
		}
		if (cur < k) continue; 
//		cout << '\n';
		sort(len+1, len+lcur+1, cmp);
//		for (int j = 1; j <= lcur; j++)
//			cout << len[j] << '\n';
		int sum = 0;
		for (int j = 1; j <= min(lcur, m+1); j++)
			sum += len[j];
		if (sum >= k) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int tt;
	cin >> tt;
	while (tt--){
		int maxa = 0, mina = 1e9;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i], t[i] = a[i], maxa = max(maxa, a[i]), mina = min(mina, a[i]);
		sort(t+1, t+n+1, cmp);
		cur = 0; 
		for (int i = 1; i <= n; i++)
			if (a[i] != a[i-1]){
				num[++cur] = a[i];
			}
		int l = 0, r = maxa - mina; 
		while (l < r){
			int mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
//			cout << '\n'; 
		}
		cout << l << '\n';
	}
	return 0;
}

