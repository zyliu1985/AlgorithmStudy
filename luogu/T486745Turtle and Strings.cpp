#include <iostream>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int main(){
	cout.tie(0);
	int t = read();
	while (t--){
		int n = read();
		string s;
		cin >> s;
		int last = 0, ans = 0, lastmod;
		for (int i = 1; i < n; i++)
			if (s[i] != s[i-1]){
				int len = i - last;
				ans += (i - last) / 3 * 2 + ((i - last) % 3 > 0) + ((i - last) % 3 == 2 && (lastmod == 2 || lastmod == 1));
				if ((i - last) % 3 == 0 && lastmod != 0) lastmod = 2;
				else lastmod = (i - last) % 3 - ((i - last) % 3 == 2 && (lastmod == 2 || lastmod == 1));
				last = i;
			}
		cout << ans + (n - last) / 3 * 2 + ((n - last) % 3 > 0) + ((n - last) % 3 == 2 && lastmod == 2) << endl;
	}
	return 0;
}
