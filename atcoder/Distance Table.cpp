#include <iostream>
#include <algorithm>
using namespace std;

int s[55];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x;
		cin >> x;
		s[i] = s[i-1] + x;
	}
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++)
			cout << s[j-1] - s[i-1] << ' ';
		cout << '\n';
	}
	return 0;
}



