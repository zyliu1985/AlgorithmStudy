#include <iostream>
#include <algorithm>
using namespace std;

int box[20000005], ans[10000005], cur;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i * i <= n; i++)
		for (int j = i+1; j * j <= n; j++)
			box[i * i + j * j]++;
	int num = 0;
	for (int i = 1; i <= n; i++)
		if (box[i] == 1) num++, ans[++cur] = i;
	cout << num << '\n';
	for (int i = 1; i <= cur; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}

