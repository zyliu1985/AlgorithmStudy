#include <iostream>
#include <cstring>
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
bool a[35];
int f[35][65];
int dfs(bool limit, bool lead, int pos, int cha){
	if (pos == 0) return cha >= 32;
	if (!limit && !lead && f[pos][cha] != -1) return f[pos][cha];
	int re = 0, up;
	if (limit) up = a[pos];
	else up = 1;
	for (int i = 0; i <= up; i++)
		re += dfs(limit && (i == up), lead && (i == 0), pos - 1, cha + (i == 0 ? (!lead) : -1));
	if (!limit && !lead) f[pos][cha] = re;
//	cout << pos << ' ' << cha << ':' << f[pos][cha] << ' ' << re << endl;
	return re;
}
int solve(int x){
	int len = 0;
	while (x > 0){
		a[++len] = x % 2;
		x /= 2;
	}
	return dfs(true, true, len, 32);
}
int main(){
	cout.tie(0);
	memset(f, -1, sizeof(f));
	int l = read(), r = read();
	cout << solve(r) - solve(l-1) << endl;
	return 0;
}
