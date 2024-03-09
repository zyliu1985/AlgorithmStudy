#include <iostream>
#include <algorithm>
using namespace std;

string a;
int main(){
	int n, k;
	cin >> n >> k;
	cin >> a;
	a = ' ' + a;
	int ans = 1e9, sum = 0, cnt = 0;
	int last = 1; // 尾标记
	for (int i = 1; i <= n; i++){ // 头标记
		if (a[i] == '1'){
			if (cnt == 0){ // 无意义
				last++;
				continue;
			}
			sum++;
			cnt++;
		} else {
			cnt++;
		}
		while (cnt >= k){
			ans = min(ans, sum);
			if (a[last] == '0') cnt--;
			else {
				cnt--;
				sum--;
			}
			last++;
		}
	}
	cout << ans << endl;
	return 0;
}