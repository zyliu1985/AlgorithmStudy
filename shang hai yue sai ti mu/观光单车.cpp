#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int len(int a){
	int cnt = 0;
	while (a > 0){
		a /= 10;
		cnt++;
	}
	return cnt;
}

int main(){
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int left = 1, right = n, cnt = 0;
	while (right >= left){
		if (a[left] + a[right] > t){
			cnt++;
			cout << "Y " << a[right] << '|' <<endl;
			cout << "0--";
			for (int i = 1; i <= len(a[right]); i++) cout << '-';
			cout << "0" << endl;
			right--;
		} else {
			cnt++;
			cout << "Y|" << a[left] << '|' << a[right] << '|' << endl;
			cout << "0--";
			for (int i = 0; i <= len(a[left])+len(a[right]); i++) cout << '-';
			cout << "0" << endl;
			right--;
			left++;
		}
	}
	cout << cnt << endl;
	return 0;
}

/*
6
4000 2839 1849 812  1623 2483 1273
*/