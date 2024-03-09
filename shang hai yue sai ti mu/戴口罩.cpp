#include <iostream>
using namespace std;

int T[7] = {-1, -1, -1, -1, -1, 6, 6};
int main(){
	int n;
	cin >> n;
	int day = 0, cnt = 10;
	int cur = 0;
	while (cnt != n){
		day++;
		cnt += T[cur++];
		cur = cur == 7 ? 0 : cur;
	}
	cout << day << endl;
	return 0;
}