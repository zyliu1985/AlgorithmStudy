#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int i = 1, j = 2, k = 0;
	while (i + k <= n && j + k <= n){
		if (a[i+k] == a[j+k]) k++;
		else{
			int t = a[i + k] - a[j + k];
			if (t > 0) i += k + 1;
			else j += k + 1;
			if (i == j) j++;
			k = 0; 
		}
	}
	for (int l = min(i, j); l != (min(i, j) + n - 2) % n + 1; l = l % n + 1)
		cout << a[l] << ' ';
	cout << a[(min(i, j) + n - 2) % n + 1] << '\n';
	cout << '\n';
	return 0;
}

