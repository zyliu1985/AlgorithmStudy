#include <iostream>
#include <algorithm>
using namespace std;

string ans;
int a[1000005];
int box[1000005];
int otr[1000005];
int ord[500005];
int n;
int l = 1, r = 2*n, cl, cr;
bool solve(){
	bool flag = true;
	for (int i = 2; i <= n; i++){
		bool lok = (otr[l] == cl-1 || otr[l] == cr+1) && (l != cl);
		bool rok = (otr[r] == cl-1 || otr[r] == cr+1) && (r != cr);
		if (lok){
			if (cl-1 == otr[l]) cl--;
			else if (cr+1 == otr[l]) cr++;
			ans += 'L';
			ord[i] = a[l];
			l++;
		} else if (rok){
			if (cl-1 == otr[r]) cl--;
			else if (cr+1 == otr[r]) cr++;
			ans += 'R';
			ord[i] = a[r];
			r--;
		} else {
			flag = false;
			break;
		}
		if (l > cl || r < cr) exit(9);
	}
	if (!flag) return false;
	for (int i = n; i >= 1; i--)
		if (ord[i] == a[l]){
			ans += 'L';
			l++;
		} else if (ord[i] == a[r]){
			ans += 'R';
			r--;
		}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= 2 * n; i++){
			box[i] = 0;
			otr[i] = 0;
			ord[i] = 0;
		}
		for (int i = 1; i <= 2 * n; i++){
			cin >> a[i];
			if (!box[a[i]]) box[a[i]] = i;
			else otr[i] = box[a[i]], otr[box[a[i]]] = i;
		}
		ans = "";
		l = 1, r = 2*n;
		cl = cr = otr[1];
		ans += 'L';
		ord[1] = a[1];
		l++;
		if (solve()) cout << ans << '\n';
		else{
			ans = "";
			l = 1, r = 2*n;
			cl = cr = otr[2*n];
			ans += 'R';
			ord[1] = a[2*n];
			r--;
			if (solve()) cout << ans << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}

