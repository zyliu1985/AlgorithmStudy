#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, d;
int v[100005];
int a[100005];
long long price = 0;

int main() {
//	freopen("./J-data/road11.in", "r", stdin);
//	freopen("./ans.txt", "w", stdout);
	cin >> n >> d;
	
	for(int i = 1; i<= n-1; i++) {
		cin >> v[i];
//		dis += v[i];
	}
	
	for(int i = 1; i<= n; i++) {
		cin >> a[i];
	}
	
	double pp = 1.0 / d;
	double leftOil = 0.0;
	for(int i = 1; i < n;) {
		long long dd = 0;
		int cp = a[i];
		int c = i;
		for(int j = i + 1; j <= n; j++) {
			dd += v[j - 1];
			i = j;
			if(a[c] > a[j]) {
				break;
			}
		}
		
		double need = dd * pp;
		long long addOil = ceil(need - leftOil);
		price += addOil * cp;
		leftOil += addOil - need;
	}
	
	cout << price;
	return 0;
}
