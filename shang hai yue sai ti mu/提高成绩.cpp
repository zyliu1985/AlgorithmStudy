#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	sort(a+1, a+n+1);
	while (sum / n < 90){
		cnt++;
		sum += 100-a[cnt];
	}
	cout << cnt << endl;
	return 0;
}