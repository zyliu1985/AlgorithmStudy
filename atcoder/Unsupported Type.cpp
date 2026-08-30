#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x;
	cin >> x;
	for (int i = 1; i <= n; i++)
		if (a[i] == x){
			cout << "Yes\n";
			return 0;
		}
	cout << "No\n";
	return 0;
}



