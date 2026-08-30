#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int l[100005]; 
bool check(int x){
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += l[i] / x;
	return sum >= k;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	int l = 0, r = 1e8;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l << '\n';
	return 0;
}



