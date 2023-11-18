#include <iostream>
using namespace std;

int main(){
	long long n, t;
	cin >> n;
	t = n;
	int sum = 0;
	while (n > 0){
		sum += n%10;
		n /= 10;
	}
	n = t;
	if (n%sum == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}