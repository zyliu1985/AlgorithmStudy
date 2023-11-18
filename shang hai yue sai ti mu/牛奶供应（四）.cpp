#include <iostream>
#include <algorithm>
using namespace std;

struct dmilk{
	int w, p;
} a[100005];
bool cmp(dmilk x, dmilk y){
	return x.p < y.p;
}

int main(){
	int n, m, l, ans = 0;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++){
		int d;
		cin >> d >> a[i].w >> a[i].p;
		a[i].p += m-d;
	}
	sort(a+1, a+n+1, cmp);
	int i = 0;
	while (true){
		if (l >= a[i].w){
			i++;
			l -= a[i].w;
			ans += a[i].w*a[i].p;
		} else {
			i++;
			ans += l*a[i].p;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}