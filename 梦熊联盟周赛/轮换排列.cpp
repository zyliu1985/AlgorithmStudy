#include<iostream>
using namespace std;

int a[500005];
int main() {
	int n, m, cur = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 1; i <= m; i++){
		long long x = 0;
		char op;
		string s;
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len - 1; i++)
			x = x * 10 + (s[i] - '0');
		op = s[len-1];
		if (op == 'a'){
			x %= n;
			cur = (cur - x + n - 1) % n + 1;
		} else {
			x %= 3;
			for (int i = 1; i <= x; i++){
				int a1, a2, a3;
				a1 = a[cur];
				a2 = a[cur % n + 1];
				a3 = a[(cur + 1) % n + 1];
				a[cur] = a3;
				a[cur % n + 1] = a1;
				a[(cur + 1) % n + 1] = a2;
			}
		}
	}
	int tot = cur;
	cout << a[cur] << ' ';
	cur = cur % n + 1;
	while (cur != tot){
		cout << a[cur] << ' ';
		cur = cur % n + 1;
	}
	return 0;
}