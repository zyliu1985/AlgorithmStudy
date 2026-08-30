#include <bits/stdc++.h>
using namespace std;

int n, mn, ht;
char c;
int m[100005];

int calc(int l, int r) {
	int sum = 0;
	for (int i = 0; i < (r - l) / 2; i++) {
		sum += abs(m[l + i] - m[r - i - 1]);
	}
	return abs(sum);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
	}
	for (int i = 1; i <= n; i++) {
		mn = 2147483647;
		for (int j = 0; j <= n - i; j++) {
			ht = calc(j, j + i);
			mn = min(mn, ht);
		}
		cout << mn << " ";
	}
}
