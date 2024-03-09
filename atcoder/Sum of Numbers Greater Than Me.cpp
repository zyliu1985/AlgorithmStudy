#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], t[200005];
long long s[200005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		t[i] = a[i];
	}
	sort(a+1, a+n+1);
	for (int i = n; i >= 1; i--){
		s[i] = s[i+1] + a[i];
	}
	for (int i = 1; i <= n; i++){
		int cur = upper_bound(a+1, a+n+1, t[i]) - a;
		cout << s[cur] << ' ';
	}
	return 0;
}