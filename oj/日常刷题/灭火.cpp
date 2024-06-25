#include <iostream>
using namespace std;

int main() {
	int n;
	long long m;
	cin >> n >> m;
	long long cnt = 0;
	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		long long w;
		cin >> w;
		sum += w;
		long long x = sum / m;
		cnt += x;
		sum -= x*m;
	}
	
	if(sum > 0) cnt++;
	
	cout << cnt << endl;
	return 0;
}