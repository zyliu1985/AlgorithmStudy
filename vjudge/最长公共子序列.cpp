#include <iostream>
#include <algorithm>
using namespace std;

int dict[100005], a[100005], f[100005], cur; 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		dict[x] = i;
	}
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[i] = dict[x];
//		cout << a[i] << ' ';
	}
//	cout << '\n';
	for (int i = 1; i <= n; i++){
		int t = lower_bound(f+1, f+cur+1, a[i]) - f;
		if (t > cur) cur++;
		f[t] = a[i];
	}
	cout << cur;
	return 0;
}



