#include <iostream>
using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	while (a.size() < b.size()) a = "0" + a;
	while (b.size() < a.size()) b = "0" + b;
	int len = a.size();
	int ans = 0;
	bool jin = false;
	for (int i = len-1; i >= 0; i--)
		if (a[i] + b[i] - '0' * 2 + jin > 9){
			ans++;
			jin = true;
		} else
			jin = false;
	cout << ans << endl;
	return 0;
}