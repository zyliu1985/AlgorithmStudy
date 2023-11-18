#include <iostream>
#include <algorithm>
using namespace std;

int a[16] = {0,1,3,5,7,9,11,13,14,12,10,8,6,4,2,0};

int main(){
	sort(a+1, a+15+1);
	int cnt = 1;
	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= i; j++){
			cout << a[cnt] << ' ';
			cnt++;
			//cout << "cnt=" << cnt << ' ';
		}
		cout << endl;
	}
	return 0;
}