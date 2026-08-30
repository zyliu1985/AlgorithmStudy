#include <bits/stdc++.h>
using namespace std;
int g, p;
struct plane{
	int w;
	int id;
}a[100010];
bool cmp(const plane&x, const plane&y){
	if (x.w < y.w) return 1;
	if (x.id < y.id) return 1;
	return 0; 
}
int main(){
	cin >> g >> p;
	for (int i = 1; i <= p; i++){
		cin >> a[i].w;
		a[i].id = i;
	}
	sort(a + 1, a + p + 1, cmp);
	int ans = INT_MAX;
	int tot = 0;
	for (int i = 1; i <= p; i++){
		if (a[i].w <= i - 1 - tot){
			ans = min(ans, a[i].id);
			tot++;
		}
	}
	cout << min(ans - 1, p) << endl;
	return 0;
}
