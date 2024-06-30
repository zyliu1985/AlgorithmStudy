#include <iostream>
using namespace std;

int a[1000005];
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 1;
	for (int i = n-1; i >= 0; i--){
		if (s[i] != '0')a[i+1] = x;
		if (x != 1e6) x = min(x * 2, 1000000);
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans += 
	return 0;
}