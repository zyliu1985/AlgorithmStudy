#include <iostream>
using namespace std;

string s[10];
int n, st[10], ans;
void nextst(){
	for (int i = 1; i <= 6; i++)
		st[i] = (st[i] + 1) % n;
}
int cal(){
	int re = 0;
	for (int i = 1; i <= n; i++){
		int a, b, c;
		a = s[1][st[1]] - '0';
		b = s[3][st[3]] - '0';
		c = (s[5][st[5]] - '0') * 10 + (s[6][st[6]] - '0');
		char x, y;
		x = s[2][st[2]];
		y = s[4][st[4]];
		double num;
		if (x == '+') num = a + b;
		else if (x == '-') num = a - b;
		else if (x == '*') num = a * b;
		else if (b != 0) num = a * 1.0 / b;
		else continue;
		if (y == '>') re += (num > c);
		else if (y == '<') re += (num < c);
		else re += (num == c);
		nextst();
	}
	return re;
}
void dfs(int x){
	if (x > 6){
		ans = max(ans, cal());
		return;
	}
	for (int i = 0; i < n; i++){
		st[x] = i;
		dfs(x+1);
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= 6; i++)
		cin >> s[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}