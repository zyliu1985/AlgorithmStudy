#include <iostream>
using namespace std;

int a[1000005];

int main(){
	int n, t;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> t;
	int l = 1, r = n;
	while (l < r){
		if (a[l] + a[r] == t){
			cout << "Yes" << endl;
			return 0;
		} else if (a[l] + a[r] > t){
			r--;
		} else {
			l++;
		}
	}
	cout << "No" << endl;
	return 0;
}