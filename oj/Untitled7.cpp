#include <iostream>
using namespace std;

int s[1000005];
int main(){
	int n;
	cin >> n;
	s[0] = 1;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s[i] = (s[i-1] * x) % 10000;
	}
	for (int i = 1; i <= n; i++)
		cout << s[i-1]
	return 0;
}