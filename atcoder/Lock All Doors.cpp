#include <iostream>
#include <algorithm>
using namespace std;

bool l[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	bool flag = false;
	int num = 0;
	for (int i = 1; i <= r; i++){
		if (!l[i] && !flag) flag = true, num++;
		else if (flag) num += l[i] + 1;
	}
	flag = false;
	for (int i = n; i > r; i--){
		if (!l[i] && !flag) flag = true, num++;
		else if (flag) num += l[i] + 1;
	}
	cout << num << '\n';
	return 0;
}

