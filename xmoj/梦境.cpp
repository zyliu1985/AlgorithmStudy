#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	bool flag = n & 1;
	for (int i = 1; i <= n; i++){
		if (flag) cout << "I hate ";
		else cout << "I love ";
		if (i != n) cout << "that ";
		else cout << "it";
		flag ^= 1;
	} 
	return 0;
}



