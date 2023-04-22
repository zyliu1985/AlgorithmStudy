#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a[1000050];
int t=0; // 记录已读过的和重复的书本数量

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == a[i-1]) {
			t++;
			i--;
			n--;
		}
	}
	cout << "n=" << n << ",t=" << t << endl;
	int i = 0, x = 1;
	while(i<n) {
		if(a[i] == x) {
			t++;
			i++;
		} else if(t >= 2) {
			t--;
		} else if(t ==1 && n-i >= 1) {
			n--;
		} else if(t == 0 && n-i >= 2) {
			t++;
			n-=2;
		}
		
		x++;
	}
	
	if(t >= 2) {
		x += t -1;
	}

	cout << x-1 << endl;
	return 0;
}