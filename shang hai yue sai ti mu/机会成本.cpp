#include <iostream>
using namespace std;

int a[500005], b[500005];
int main(){
	int n;
	cin >> n;
	int maxd = 0, maxi = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		if (a[i]-b[i] > maxd){
			maxd = a[i]-b[i];
			maxi = i;
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){
		if (maxi == i) sum += a[i];
		else sum += b[i];
	}
	cout << sum << endl;
	return 0;
}