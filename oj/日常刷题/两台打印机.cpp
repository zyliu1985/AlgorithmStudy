#include <iostream>
using namespace std;

int a[105], f[50005];
int main(){
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = sum / 2 + sum % 2; j >= a[i]; j--)
			f[j] = max(f[j], f[j - a[i]] + a[i]);
	cout << max(f[sum / 2 + sum % 2], sum - f[sum / 2 + sum % 2]) << endl;
	return 0;
}